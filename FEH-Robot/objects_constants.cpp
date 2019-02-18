#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "objects_constants.h"

// Motors
FEHMotor leftMotor(FEHMotor::Motor0,9.0);
FEHMotor rightMotor(FEHMotor::Motor1,9.0);
FEHServo rotateServo(FEHServo::Servo0);
FEHServo bendServo(FEHServo::Servo1);

// Sensors
DigitalEncoder leftEncoder(FEHIO::P0_0);
DigitalEncoder rightEncoder(FEHIO::P0_1);
DigitalInputPin frontLeftSwitch(FEHIO::P0_2);
DigitalInputPin frontRightSwitch(FEHIO::P0_3);
DigitalInputPin backLeftSwitch(FEHIO::P0_4);
DigitalInputPin backRightSwitch(FEHIO::P0_5);
AnalogInputPin cds(FEHIO::P0_6);
