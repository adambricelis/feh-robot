#include "drive.h"
#include "objects_constants.h"
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>

/**
 * Sets power percentages of drivetrain motors.
 *
 * @param left
 *          left motor power percentage
 * @param right
 *          right motor power percentage
 */
void setMotors(float left, float right) {
    leftMotor.SetPercent(left);
    rightMotor.SetPercent(right);
}

/**
 * Sets power percentages of drivetrain motors directionally.
 *
 * @param left
 *          left motor power percentage
 * @param right
 *          right motor power percentage
 * @param direction
 *          true if driving forward, false if driving backward
 */
void setMotorsWithDirection(float left, float right, bool direction) {
    if (direction) {
        setMotors(left, right);
    } else {
        setMotors(-left, -right);
    }
}

/**
 * Stops left and right drivetrain motors.
 */
void stopMotors() {
    leftMotor.Stop();
    rightMotor.Stop();
}

/**
 * Resets encoders for left and right drivetrain motors.
 */
void resetEncoders() {
    leftEncoder.ResetCounts();
    rightEncoder.ResetCounts();
}

/**
 * Drives at the given motorPercent for the given distance in inches.
 *
 * @param motorPercent
 *          positive percentage at which to set left and right motors
 * @param direction
 *          true if driving forward, false if driving backward
 * @param inches
 *          positive distance for robot to travel
 */
void driveStraightDistance(float motorPercent, bool direction, float inches) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(motorPercent, motorPercent, direction);

    // Run motors until desired distance is reached
    while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < (ENCODER_COUNTS_PER_INCH * inches)) {

        // High-precision driving if going forward
//        if (direction) {
//            if (leftEncoder.Counts() > rightEncoder.Counts()) {
//                setMotors(motorPercent - 1, motorPercent);
//            } else if (leftEncoder.Counts() < rightEncoder.Counts()) {
//                setMotors(motorPercent, motorPercent - 1);
//            } else {
//                setMotors(motorPercent, motorPercent);
//            }
//        }
    }

    stopMotors();
}

/**
 * Drives at the given motorPercent for the given time in seconds.
 *
 * @param motorPercent
 *          positive percentage at which to set left and right motors
 * @param direction
 *          true if driving forward, false if driving backward
 * @param seconds
 *          positive time for robot to travel
 */
void driveStraightTime(float motorPercent, bool direction, float seconds) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(motorPercent, motorPercent, direction);

    // Run motors until desired distance is reached
    Sleep(seconds);

    stopMotors();
}

/**
 * Drives along the arc dictated by the given left and right
 * motor percentages for the given distance in inches.
 *
 * @param left
 *          left motor power percentage
 * @param right
 *          right motor power percentage
 * @param direction
 *          true if driving forward, false if driving backward
 * @param inches
 *          positive distance for robot to travel
 */
void driveArcDistance(float left, float right, bool direction, float inches) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(left, right, direction);

    // Run motors until desired distance is reached
    while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < (ENCODER_COUNTS_PER_INCH * inches));

    stopMotors();
}

/**
 * Drives along the arc dictated by the given left and right
 * motor percentages for the given time in seconds.
 *
 * @param left
 *          left motor power percentage
 * @param right
 *          right motor power percentage
 * @param direction
 *          true if driving forward, false if driving backward
 * @param seconds
 *          positive time for robot to travel
 */
void driveArcTime(float left, float right, bool direction, float seconds) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(left, right, direction);

    // Run motors until desired time is reached
    Sleep(seconds);

    stopMotors();
}

/**
 * Turns a specified number of degrees to the left or right at the given motor percentage
 *
 * @param motorPercent
 *          positive percentage at which to set left and right motors
 * @param turnLeft
 *          true if turning left, false if turning right
 * @param degrees
 *          positive number of degrees to turn
 */
void turn(float motorPercent, bool turnLeft, float degrees) {
    resetEncoders();

    // Set both motors to desired %
    if (turnLeft) {
        setMotors(-motorPercent, motorPercent);
    } else {
        setMotors(motorPercent, -motorPercent);
    }

    // Run motors until desired turn angle is reached
    while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < ENCODER_COUNTS_PER_DEGREE * degrees);

    // Stop both motors
    stopMotors();
}
