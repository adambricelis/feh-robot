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
    // Competition run
    startRun();

    // Drives to DDR
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 11.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 101);

    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 9.1);
    Sleep(0.25);

    // Plays Dance Dance Robot
    playDDR();

    // Drives up pinball ramp
    driveArcDistance(RAMP_MOTOR_PERCENT + 5.8, RAMP_MOTOR_PERCENT, BACKWARD, 22.0);
    driveArcDistance(RAMP_MOTOR_PERCENT*1.4, DEFAULT_MOTOR_PERCENT*1.1, BACKWARD, 15.0); //first used to be 1.33

    // Drives to token machine
    turn(TURN_MOTOR_PERCENT, RIGHT, 106); // 104
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0); //for A: 4.0
    driveArcDistance(DEFAULT_MOTOR_PERCENT, FAST_MOTOR_PERCENT, FORWARD, 10.0); // 9.0
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.5); //for A: 3.0, prev: 2.0
    turn(TURN_MOTOR_PERCENT, LEFT, 26);
    driveStraightTime(40.0, FORWARD, 0.75);

    //Drops token
    dropToken();

    // Aligns with wall before foosball (not corner)
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 0.75);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT+4.0, BACKWARD, 8.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 2.0);
    driveArcDistance(SLOW_MOTOR_PERCENT+1.0, FAST_MOTOR_PERCENT, BACKWARD, 6.0);
    driveArcDistance(SLOW_MOTOR_PERCENT+3.0, FAST_MOTOR_PERCENT, BACKWARD, 3.25);
    driveStraightTime(40.0, BACKWARD, 1.0);

    // Drives off of wall
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0);

    // Drives to foosball corner
    turn(TURN_MOTOR_PERCENT, LEFT, 89);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.7); //for A: 2.13
    driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 8.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 138);
    driveStraightTime(40.0, BACKWARD, 0.6);

    // Slides foosball counters
    slideFoosball();

    // Drives to claw lever
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 1.0);

    // Flips claw lever
    flipLever();

    // Drives back to pinball ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 5.5);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 14.0);

    // Drives down pinball ramp
    driveArcDistance((DEFAULT_MOTOR_PERCENT + 3.0)*1.4, DEFAULT_MOTOR_PERCENT*1.4, BACKWARD, 15.5);
    driveArcDistance(SLOW_MOTOR_PERCENT, DEFAULT_MOTOR_PERCENT, BACKWARD, 15.5);

    // Drives to final button
    turn(FAST_MOTOR_PERCENT, LEFT, 110.0);
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 14.0);
    turn(FAST_MOTOR_PERCENT, LEFT, 38);

    // Presses final button
    driveStraightTime(FAST_MOTOR_PERCENT, FORWARD, 1.25);

    LCD.WriteLine("Done!");
    return 0;
}
