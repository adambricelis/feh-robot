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
    // BEGIN PT 2 CODE

    startRun();

    //drive to ramp
    turn(TURN_MOTOR_PERCENT, LEFT, 45);
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 16.0);   //16 was not an actual measurement
    setBreakpoint(1);

    // Drives up ramp
    driveStraightDistance(RAMP_MOTOR_PERCENT, FORWARD, 16.0);   //need to measure
    Sleep(0.5);
    setBreakpoint(2);

    //go to token machine
    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 8.0); //need to measure
    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
    setBreakpoint(3);

    //drop token
    dropToken();
    setBreakpoint(4);

    //go to lever
    turn(TURN_MOTOR_PERCENT, LEFT, 120);
    driveArcDistance(0.25, 0.50, FORWARD, 32.0);    //need to measure
    setBreakpoint(5);

    //press lever
    flipLever();


    LCD.WriteLine("Done!");
    return 0;
}
