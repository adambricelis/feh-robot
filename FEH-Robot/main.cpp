#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "drive.h"
#include "objects_constants.h"
#include "tasks.h"

int main(void)
{
    // SERVO TESTING CODE
    LCD.WriteLine("Test: dropToken()");
    setBreakpoint(0);
    dropToken();

    LCD.WriteLine("Test: flipLever()");
    setBreakpoint(0);
    flipLever();



    // SPECIAL TESTING CODE
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 6.0);
//    setBreakpoint(0);
//    turn(TURN_MOTOR_PERCENT, RIGHT, 45);
//    setBreakpoint(0);
//    turn(TURN_MOTOR_PERCENT, LEFT, 45);
//    setBreakpoint(0);
//    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
//    setBreakpoint(0);
//    turn(TURN_MOTOR_PERCENT, LEFT, 90);
//    setBreakpoint(0);



    // BEGIN PT 3 CODE

//    startRun();

//    // Drives to pinball ramp
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 6.0);
//    setBreakpoint(0);
//    turn(TURN_MOTOR_PERCENT, RIGHT, 45);
//    setBreakpoint(0);
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 12.0);
//    turn(TURN_MOTOR_PERCENT, LEFT, 90);
//    setBreakpoint(1);

//    // Drives up pinball ramp
//    driveStraightDistance(RAMP_MOTOR_PERCENT, FORWARD, 30.0);
//    setBreakpoint(2);

//    // Drives to token machine
//    turn(TURN_MOTOR_PERCENT, LEFT, 135);
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 12.0);
//    turn(TURN_MOTOR_PERCENT, LEFT, 45);
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0);
//    setBreakpoint(3);

//    // Drops token
//    dropToken();
//    setBreakpoint(4);

//    // Drives to claw lever
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 5.0);
//    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 12.0);
//    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
//    driveArcDistance(0.40, 0.25, FORWARD, 32.0);
//    setBreakpoint(5);

//    // Flips claw lever
//    flipLever();

    // END PT 3 CODE

    LCD.WriteLine("Done!");
    return 0;
}
