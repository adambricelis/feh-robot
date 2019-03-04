#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "objects_constants.h"

// Motors
FEHMotor leftMotor(FEHMotor::Motor3,9.0);
FEHMotor rightMotor(FEHMotor::Motor2,9.0);
// TODO: change this to hacked servo
//FEHServo frontServo(FEHServo::Servo0);
FEHServo backServo(FEHServo::Servo1);

// Sensors
AnalogInputPin cds(FEHIO::P3_5);
DigitalEncoder leftEncoder(FEHIO::P3_6);
DigitalEncoder rightEncoder(FEHIO::P3_7);
