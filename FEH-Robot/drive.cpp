#include "drive.h"
#include "objects_constants.h"
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHRPS.h>
#include <math.h>

void setMotors(float left, float right) {
    leftMotor.SetPercent(left);
    rightMotor.SetPercent(right);
}

void setMotorsWithDirection(float left, float right, bool direction) {
    if (direction) {
        setMotors(left, right);
    } else {
        setMotors(-left, -right);
    }
}

void stopMotors() {
    leftMotor.Stop();
    rightMotor.Stop();
}

void resetEncoders() {
    leftEncoder.ResetCounts();
    rightEncoder.ResetCounts();
}

void runMotorsForDistance(float inches) {
    /*
     *  Continues looping while the average of the left and right encoder
     *  counts is less than the desired number of encoder counts
     */
    double startTime = TimeNow();
    while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < (ENCODER_COUNTS_PER_INCH * inches)
          && TimeNow() - startTime < DRIVE_TIMEOUT);

    stopMotors();
}

void driveStraightDistance(float motorPercent, bool direction, float inches) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(motorPercent, motorPercent, direction);

    // Run motors until desired distance is reached
    runMotorsForDistance(inches);
}

void driveStraightTime(float motorPercent, bool direction, float seconds) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(motorPercent, motorPercent, direction);

    // Run motors until desired distance is reached
    Sleep(seconds);

    stopMotors();
}

void driveArcDistance(float left, float right, bool direction, float inches) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(left, right, direction);

    // Run motors until desired distance is reached
    runMotorsForDistance(inches);
}

void driveArcTime(float left, float right, bool direction, float seconds) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(left, right, direction);

    // Run motors until desired time is reached
    Sleep(seconds);

    stopMotors();
}

void turn(float motorPercent, bool turnLeft, float degrees) {
    resetEncoders();

    // Set both motors to desired %
    if (turnLeft) {
        setMotors(-motorPercent, motorPercent);
    } else {
        setMotors(motorPercent, -motorPercent);
    }

    /*
     *  Continues looping while the average of the left and right encoder
     *  counts is less than the desired number of encoder counts
     */
    double startTime = TimeNow();
    while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < ENCODER_COUNTS_PER_DEGREE * degrees
          && TimeNow() - startTime < DRIVE_TIMEOUT);

    // Stop both motors
    stopMotors();
}

void checkHeading(float heading)
{
    // Adjusts robot until desired heading or timeout is reached
    float currentHeading = RPS.Heading();
    int startTime = TimeNow();
    while (abs(currentHeading - heading) > 0.5
           && TimeNow() - startTime < RPS_TIMEOUT
           && currentHeading >= 0) {

        // Special case for heading of 0
        if (heading == 0) {
            if (currentHeading > 180) {
                turn(SLOW_MOTOR_PERCENT, LEFT, 2);
            } else {
                turn(SLOW_MOTOR_PERCENT, RIGHT, 2);
            }
        } else {
            if (currentHeading < heading) {
                turn(SLOW_MOTOR_PERCENT, LEFT, 2);
            } else {
                turn(SLOW_MOTOR_PERCENT, RIGHT, 2);
            }
        }

        // Pauses and updates currentHeading
        Sleep(0.25);
        currentHeading = RPS.Heading();
    }
}

void checkLocationX(float x) {
    float currentHeading = RPS.Heading();
    float currentX = RPS.X();
    bool direction = abs(currentHeading - 270) < 10;
    int startTime = TimeNow();

    while (abs(currentX - x) > 0.5
           && TimeNow() - startTime < RPS_TIMEOUT
           && currentX >= 0) {
        if (x > currentX) {
            driveStraightDistance(SLOW_MOTOR_PERCENT, direction, 0.25);
        } else {
            driveStraightDistance(SLOW_MOTOR_PERCENT, !direction, 0.25);
        }

        // Pauses and updates currentX
        Sleep(0.25);
        currentX = RPS.X();
    }
}

void checkLocationY(float y) {
    float currentHeading = RPS.Heading();
    float currentY = RPS.Y();
    bool direction = currentHeading < 5 || currentHeading > 355;
    int startTime = TimeNow();

    while (abs(currentY - y) > 0.5
           && TimeNow() - startTime < RPS_TIMEOUT
           && currentY >= 0) {
        if (y > currentY) {
            driveStraightDistance(SLOW_MOTOR_PERCENT, direction, 0.25);
        } else {
            driveStraightDistance(SLOW_MOTOR_PERCENT, !direction, 0.25);
        }

        // Pauses and updates currentX
        Sleep(0.25);
        currentY = RPS.Y();
    }
}
