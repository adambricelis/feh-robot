#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "object_constants.h"


FEHMotor leftMotor(FEHMotor::Motor0,9.0);
FEHMotor rightMotor(FEHMotor::Motor1,9.0);
FEHServo rotateServo(FEHServo::Servo0);
FEHServo bendServo(FEHServo::Servo1);

DigitalEncoder leftEncoder(FEHIO::P0_0);
DigitalEncoder rightEncoder(FEHIO::P0_1);
DigitalInputPin microFrontLeft(FEHIO::PO_2);
DigitalInputPin microFrontRight(FEHIO::PO_3);
DigitalInputPin microBackLeft(FEHIO::PO_4);
DigitalInputPin microBackRight(FEHIO::PO_5);
AnalogInputPin cds (FEHIO::P0_6);
