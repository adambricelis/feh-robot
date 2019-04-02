#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "objects_constants.h"

// Motors
FEHMotor leftMotor(FEHMotor::Motor2,9.0);
FEHMotor rightMotor(FEHMotor::Motor3,9.0);
FEHMotor frontServo(FEHMotor::Motor0, 5.0);
FEHServo backServo(FEHServo::Servo0);

// Sensors
AnalogInputPin cds(FEHIO::P3_7);
DigitalEncoder leftEncoder(FEHIO::P3_0);
DigitalEncoder rightEncoder(FEHIO::P3_1);
