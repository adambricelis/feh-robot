#include "drive.h"
#include "objects_constants.h"
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>

/**
 * Sets power percentages of drivetrain motors.
 *
 * @param left: left motor power percentage
 * @param right: right motor power percentage
 */
void setMotors(float left, float right) {
    leftMotor.SetPercent(left);
    rightMotor.SetPercent(right);
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
 * @param motorPercent: percentage at which to set left and right motors
 * @param inches: distance for robot to travel
 */
void driveForDistance(float motorPercent, float inches) {
    resetEncoders();
    setMotors(motorPercent, motorPercent);

    // Run motors until desired distance is reached
    while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < (ENCODER_COUNTS_PER_INCH * inches));
    stopMotors();
}

/**
 * Turns a specified number of degrees to the left or right at the given motor percentage
 *
 * @param motorPercent: percentage at which to set left and right motors
 * @param turnLeft: flag to turn left or right
 * @param degrees: number of degrees to turn
 */
void turn(float motorPercent, bool turnLeft, int degrees) {
    // Reset encoder counts
    rightEncoder.ResetCounts();
    leftEncoder.ResetCounts();

    // Set both motors to desired %
    // Switches sign of % to turn left or right
    if (turnLeft) {
        setMotors(-motorPercent, motorPercent);
    } else {
        setMotors(motorPercent, -motorPercent);
    }

    //While the average of the left and right encoder is less than counts,
    //keep running motors
    while((leftEncoder.Counts() + rightEncoder.Counts()) / 2.0 < ENCODER_COUNTS_PER_DEGREE * degrees);

    // Stop both motors
    stopMotors();
}

/**
 * Sets motors to the given percentage and drives until switches
 * activated in accordance with hitFront and hitBoth.
 *
 * @param motorPercent: percentage at which to set left and right motors
 * @param hitFront: flag to expect to hit front or back switches
 * @param hitBoth: flag to expect to hit left and/or right switches
 */
void driveToCollision(float motorPercent, bool hitFront, bool hitBoth) {
    setMotors(motorPercent, motorPercent);

    if (hitFront) {
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
