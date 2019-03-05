#ifndef OBJECTS_CONSTANTS_H
#define OBJECTS_CONSTANTS_H

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>

// Timeouts
const float START_TIMEOUT = 10.0;

/*
 * Drivetrain constants
 */

// Motor percentages
const float SLOW_MOTOR_PERCENT = 10.0;
const float DEFAULT_MOTOR_PERCENT = 25.0;
const float FAST_MOTOR_PERCENT = 50.0;
const float TURN_MOTOR_PERCENT = 30.0;
const float RAMP_MOTOR_PERCENT = 50.0;

// Turning constants
const bool LEFT = true;
const bool RIGHT = false;

// Directional constants
const bool FORWARD = true;
const bool BACKWARD = false;
const bool UP = true;
const bool DOWN = false;

// driveToCollision() constants
const bool HIT_BOTH = true;
const bool HIT_EITHER = false;

// Encoder constants
const float ENCODER_COUNTS_PER_INCH = 33.7408479;
const float ENCODER_COUNTS_PER_DEGREE = 2.25;

/*
 * Light color constants
 */

// Light color enum
enum LightColor {
    RedLight,
    BlueLight,
    NoLight
};

// Light color voltage values
const float RED_LIGHT = 0.379;
const float BLUE_LIGHT = 0.765;
const float NO_LIGHT = 3.205;
// Error bound for light measurement values
const float LIGHT_EPSILON = 0.175;

/*
 * Microswitch constants
 */

// Microswitch ids
enum Switch {
    FrontLeftSwitch,
    FrontRightSwitch,
    BackLeftSwitch,
    BackRightSwitch
};

/*
 * Other constants
 */

// Servo arm values
// TODO: fix this stuff
const int TOKEN_DOWN_ANGLE = 0;
const int LEVER_DOWN = 0;
const int FOOS_DOWN = 0;

// Motors
extern FEHMotor leftMotor;
extern FEHMotor rightMotor;
extern FEHMotor frontServo;
extern FEHServo backServo;

// Sensors
extern AnalogInputPin cds;
extern DigitalEncoder leftEncoder;
extern DigitalEncoder rightEncoder;

#endif
