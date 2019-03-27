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
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 10.5);
    turn(TURN_MOTOR_PERCENT, RIGHT, 95);

    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 9.0);
    Sleep(0.25);

    // Plays Dance Dance Robot
    playDDR();

    // Drives up pinball ramp
    driveArcDistance(RAMP_MOTOR_PERCENT + 6.0, RAMP_MOTOR_PERCENT, BACKWARD, 22.0);
    driveArcDistance(RAMP_MOTOR_PERCENT*1.2, DEFAULT_MOTOR_PERCENT*1.1, BACKWARD, 14.0); //used to both be 1.1

    // Drives to token machine
    turn(TURN_MOTOR_PERCENT, RIGHT, 100);
    driveArcDistance(DEFAULT_MOTOR_PERCENT, FAST_MOTOR_PERCENT, FORWARD, 15.0); // 15.5
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0); // 1.0
    turn(TURN_MOTOR_PERCENT, LEFT, 35);
    driveStraightTime(FAST_MOTOR_PERCENT, FORWARD, 0.75);

    //Drops token
    dropToken();

    // Aligns with wall before foosball (not corner)
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 0.75);
    driveArcDistance(SLOW_MOTOR_PERCENT+1.0, FAST_MOTOR_PERCENT, BACKWARD, 14.0);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 3.0);
    driveStraightTime(FAST_MOTOR_PERCENT, BACKWARD, 0.75);

    // Drives off of wall
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0);

    // Drives to foosball corner
    turn(TURN_MOTOR_PERCENT, LEFT, 89);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 0.5); //used to be 1.1
    driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 8.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 138);
    driveStraightTime(FAST_MOTOR_PERCENT, BACKWARD, 0.6);

    // Slides foosball counters
    slideFoosball();

    // Drives to claw lever
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 1.0);

    // Flips claw lever
    flipLever();

    // Drives back to pinball ramp
    turn(TURN_MOTOR_PERCENT, RIGHT, 20);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 4.0);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 15.0);

    // Drives down pinball ramp
    driveArcDistance((DEFAULT_MOTOR_PERCENT + 3.0)*1.4, DEFAULT_MOTOR_PERCENT*1.4, BACKWARD, 15.0);
    driveArcDistance(SLOW_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 20.0);

    // Drives to final button
    turn(TURN_MOTOR_PERCENT, LEFT, 90.0);
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 10.0);
    turn(TURN_MOTOR_PERCENT, LEFT, 45);

    // Presses final button
    driveStraightTime(FAST_MOTOR_PERCENT, FORWARD, 1.1);

    LCD.WriteLine("Done!");
    return 0;
}
