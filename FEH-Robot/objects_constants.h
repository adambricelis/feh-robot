#ifndef OBJECTS_CONSTANTS_H
#define OBJECTS_CONSTANTS_H

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>

// Timeouts
const float START_TIMEOUT = 15.0;

/*
 * Drivetrain constants
 */

// Motor percentages
const float DEFAULT_MOTOR_PERCENT = 25.0;

// Turning constants
const bool LEFT = true;
const bool RIGHT = false;

// Directional constants
const bool FORWARD = true;
const bool BACKWARD = false;

// driveToCollision() constants
const bool HIT_BOTH = true;
const bool HIT_EITHER = false;

// Encoder constants
// TODO: update to account for larger wheels
const float ENCODER_COUNTS_PER_INCH = 30;
// TODO: update to account for larger wheels
const float ENCODER_COUNTS_PER_DEGREE = 10;

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
const float RED_LIGHT = 0.267;
const float BLUE_LIGHT = 0.952;
const float NO_LIGHT = 3.205;
// Error bound for light measurement values
const float LIGHT_EPSILON = 0.30;

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
const int TOKEN_DOWN = 0;
const int LEVER_DOWN = 0;
const int FOOS_DOWN = 0;

// Motors
extern FEHMotor leftMotor;
extern FEHMotor rightMotor;
extern FEHServo rotateServo;
extern FEHServo bendServo;

// Sensors
extern DigitalEncoder leftEncoder;
extern DigitalEncoder rightEncoder;
extern DigitalInputPin frontLeftSwitch;
extern DigitalInputPin frontRightSwitch;
extern DigitalInputPin backLeftSwitch;
extern DigitalInputPin backRightSwitch;
extern AnalogInputPin cds;

#endif
