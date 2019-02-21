#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "drive.h"
#include "objects_constants.h"
#include "tasks.h"
#include "additional_functions.h"

int main(void)
{
    // BEGIN PT 1 STEEP RAMP CODE

    startRun();

    // Drives to ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0);
    turn(TURN_MOTOR_PERCENT, LEFT, 90);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 11.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 55);

    // Drives to claw lever
    driveStraightDistance(RAMP_MOTOR_PERCENT, FORWARD, 34.0);
    driveArcDistance(27.0, 16.0, FORWARD, 2.0);
    driveArcDistance(42.0, 10.0, FORWARD, 5.0);
    turn(TURN_MOTOR_PERCENT, LEFT, 75);

    // Activates claw lever
    flipLever();

    // Drives back down ramp
    turn(-TURN_MOTOR_PERCENT, RIGHT, 75);
    driveArcDistance(42.0, 10.0, FORWARD, 2.0);
    driveArcDistance(16.0, 10.0, FORWARD, 4.0);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);

    // END PT 1 STEEP RAMP CODE

    LCD.WriteLine("Done!");
    return 0;
}
