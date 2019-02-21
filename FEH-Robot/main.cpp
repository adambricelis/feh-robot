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
    setBreakpoint(1);

    // Drives to claw lever
    driveStraightDistance(RAMP_MOTOR_PERCENT, FORWARD, 30.0);
    driveArcDistance(30.0, 15.0, FORWARD, 12.0);
    turn(TURN_MOTOR_PERCENT, LEFT, 75);
    setBreakpoint(2);

    // Activates claw lever
    flipLever();
    setBreakpoint(3);

    // Drives back down ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 3.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);
    setBreakpoint(4);

    // END PT 1 STEEP RAMP CODE

    LCD.WriteLine("Done!");
    return 0;
}
