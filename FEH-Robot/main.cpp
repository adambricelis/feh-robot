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

//    startRun();

//    // Drives to ramp
//    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0);
//    turn(DEFAULT_MOTOR_PERCENT, LEFT, 90);
//    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 11.0);
//    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 45);
//    setBreakpoint(1);

//    // Drives to claw lever
//    driveDistance(RAMP_MOTOR_PERCENT, FORWARD, 40.0);
//    setBreakpoint(2);

//    // Activates claw lever
//    flipLever();
//    setBreakpoint(3);

//    // Drives back down ramp
//    driveDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 3.0);
//    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 90);
//    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);
//    setBreakpoint(4);

    // END PT 1 STEEP RAMP CODE

    // BEGIN PT 1 PINBALL RAMP CODE

    startRun();

    // Drives to pinball ramp
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 6.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 45);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 16.0);
    turn(DEFAULT_MOTOR_PERCENT, LEFT, 90);
    setBreakpoint(1);

    // Drives up pinball ramp
    driveDistance(RAMP_MOTOR_PERCENT, FORWARD, 40.0);
    setBreakpoint(2);

    // Drives to claw
    turn(DEFAULT_MOTOR_PERCENT, LEFT, 135);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 18.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 90);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 12.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 45);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 6.0);
    setBreakpoint(3);

    // Activates claw lever
    flipLever();
    setBreakpoint(4);

    // Drives down steep ramp
    driveDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 10.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 180);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);
    setBreakpoint(5);

    // END PT 1 PINBALL RAMP CODE

    LCD.WriteLine("Done!");
    return 0;
}
