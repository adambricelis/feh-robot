#ifndef OBJECTS_CONSTANTS_H
#define OBJECTS_CONSTANTS_H

#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>

//color values
const float BLUE_MIN = 0;
const float RED_MIN = 0;

//switch IDs
const int FRONT_LEFT_SW = 1;
const int FRONT_RIGHT_SW = 2;
const int BACK_LEFT_SW = 3;
const int BACK_RIGHT_SW = 4;

//motor, servo values
const int TOKEN_DOWN = 0;
const int LEVER_DOWN = 0;
const int FOOS_DOWN = 0;


//motors
extern FEHMotor leftMotor;
extern FEHMotor rightMotor;
extern FEHServo rotateServo;
extern FEHServo bendServo;

//sensors
extern DigitalEncoder leftEncoder;
extern DigitalEncoder rightEncoder;
extern DigitalInputPin microFrontLeft;
extern DigitalInputPin microFrontRight;
extern DigitalInputPin microBackLeft;
extern DigitalInputPin microBackRight;
extern AnalogInputPin cds;


#endif
