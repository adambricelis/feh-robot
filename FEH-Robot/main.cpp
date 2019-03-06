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
    // TEST CODE

    slideFoosball();

    // BEGIN PT 4 CODE

//    startRun();

//    // Drives to pinball ramp
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 4.0);
//    turn(TURN_MOTOR_PERCENT, RIGHT, 45);
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 17.5);
//    turn(TURN_MOTOR_PERCENT, RIGHT, 85);

//    // Drives up pinball ramp
//    driveArcDistance(RAMP_MOTOR_PERCENT + 6.0, RAMP_MOTOR_PERCENT, BACKWARD, 22.0);
//    driveArcDistance(RAMP_MOTOR_PERCENT, DEFAULT_MOTOR_PERCENT, BACKWARD, 15.0);

//    // Drives to token machine
//    turn(TURN_MOTOR_PERCENT, RIGHT, 100);
//    driveArcDistance(DEFAULT_MOTOR_PERCENT, FAST_MOTOR_PERCENT, FORWARD, 14.5);
//    turn(TURN_MOTOR_PERCENT, LEFT, 35);
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0);

//    // Drops token
//    dropToken();

//    // Drives to claw lever
//    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 5.0);
//    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
//    driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, FORWARD, 17.0);
//    turn(TURN_MOTOR_PERCENT, LEFT, 35);

//    // Flips claw lever
//    flipLever();

    // END PT 4 CODE

    LCD.WriteLine("Done!");
    return 0;
}
