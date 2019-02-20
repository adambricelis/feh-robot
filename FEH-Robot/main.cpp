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
    // Test drive
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 3.0);
    setBreakpoint(1);
    turn(DEFAULT_MOTOR_PERCENT, LEFT, 90);
    setBreakpoint(2);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 6.0);
    setBreakpoint(3);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 45);
    setBreakpoint(4);


    // BEGIN PT 1 CODE

//    startRun();

//    // Drives to ramp
//    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 3.0);
//    turn(DEFAULT_MOTOR_PERCENT, LEFT, 90);
//    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 11.0);
//    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 45);
//    setBreakpoint(1);

//    // Drives to claw lever
//    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);
//    setBreakpoint(2);

//    // Activates claw lever
//    flipLever();
//    setBreakpoint(3);

//    // Drives back down ramp
//    driveDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 3.0);
//    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 90);
//    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);
//    setBreakpoint(4);

    // END PT 1 CODE

    LCD.WriteLine("Done!");
    return 0;
}
