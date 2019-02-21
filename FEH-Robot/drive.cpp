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
void driveDistance(float motorPercent, bool direction, float inches) {
    resetEncoders();

    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(motorPercent, motorPercent, direction);

    // High-precision driving if going forward
    if (direction) {
        // Run motors until desired distance is reached
        while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < (ENCODER_COUNTS_PER_INCH * inches));
    } else {
        // Run motors until desired distance is reached
        while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < (ENCODER_COUNTS_PER_INCH * inches));
    }

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
void turn(float motorPercent, bool turnLeft, int degrees) {
    resetEncoders();

    // Set both motors to desired %
    setMotorsWithDirection(-motorPercent, motorPercent, turnLeft);

    // Run motors until desired turn angle is reached
    while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < ENCODER_COUNTS_PER_DEGREE * degrees);

    // Stop both motors
    stopMotors();
}

/**
 * Sets motors to the given percentage and drives until switches
 * activated in accordance with hitFront and hitBoth.
 *
 * @param motorPercent
 *          postive percentage at which to set left and right motors
 * @param direction
 *          true if driving forward to hit front switches,
 *          false if driving backwards to hit back switches
 * @param hitBoth
 *          true if hitting both switches, false if hitting either switch
 */
void driveToCollision(float motorPercent, bool direction, bool hitBoth) {
    // Sets motors to motorPercent going forwards or backwards
    setMotorsWithDirection(motorPercent, motorPercent, direction);

    if (direction) {
        if (hitBoth) { // Expects to hit both front switches
            while(frontLeftSwitch.Value() || frontRightSwitch.Value());
        } else { // Expects to hit either front switch
            while(frontLeftSwitch.Value() && frontRightSwitch.Value());
        }
    } else {
        if (hitBoth) { // Expects to hit both back switches
            while(backLeftSwitch.Value() || backRightSwitch.Value());
        } else { // Expects to hit either back switch
            while(backLeftSwitch.Value() && backRightSwitch.Value());
        }
    }

    stopMotors();
}
