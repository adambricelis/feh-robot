#ifndef DRIVE_H
#define DRIVE_H

#include "objects_constants.h"

/**
 * Sets power percentages of drivetrain motors.
 *
 * @param left
 *          left motor power percentage
 * @param right
 *          right motor power percentage
 */
void setMotors(float left, float right);

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
void setMotorsWithDirection(float left, float right, bool direction);

/**
 * Stops left and right drivetrain motors.
 */
void stopMotors();

/**
 * Resets encoders for left and right drivetrain motors.
 */
void resetEncoders();

/**
 * Requires that the motors are currently running. Waits for
 * robot to travel the given distance in inches and stops
 * both motors once the robot has reached the desired distance.
 *
 * @param inches
 *          positive distance for robot to travel
 */
void runMotorsForDistance(float inches);

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
void driveStraightDistance(float motorPercent, bool direction, float inches);

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
void driveStraightTime(float motorPercent, bool direction, float seconds);

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
void driveArcDistance(float left, float right, bool direction, float inches);

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
void driveArcTime(float left, float right, bool direction, float seconds);

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
void turn(float motorPercent, bool turnLeft, float degrees);

/**
 * Ensures that the robot is a the specified heading by turning if necessary.
 *
 * @param heading
 *          positive number of degrees from 0 to 359
 */
void checkHeading(float heading);

/**
 * Requires that the robot's heading is within 10 degrees of 90 or 270.
 * Moves the robot forward or backward to the desired RPS x coordinate.
 *
 * @param x
 *          desired RPS x coordinate
 */
void checkLocationX(float x);

/**
 * Requires that the robot's heading is within 10 degrees of 0 or 180.
 * Moves the robot forward or backward to the desired RPS y coordinate.
 *
 * @param y
 *          desired RPS y coordinate
 */
void checkLocationY(float y);

#endif
