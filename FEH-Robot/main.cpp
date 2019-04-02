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
    turn(TURN_MOTOR_PERCENT, RIGHT, 96);
    checkHeading(235);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 9.1);
    Sleep(0.25);

    // Plays Dance Dance Robot
    playDDR();

    // Drives up pinball ramp
    driveArcDistance(RAMP_MOTOR_PERCENT + 5.5, RAMP_MOTOR_PERCENT, BACKWARD, 22.0);
    driveArcDistance(RAMP_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 13.0);

    // Drives to token machine
    turn(TURN_MOTOR_PERCENT, RIGHT, 110);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0);
    driveArcDistance(DEFAULT_MOTOR_PERCENT, FAST_MOTOR_PERCENT, FORWARD, 7.5);
    turn(TURN_MOTOR_PERCENT, LEFT, 50);
    checkHeading(180);
    driveStraightTime(40.0, FORWARD, 0.75);

    //Drops token
    dropToken();

    // Aligns with wall before foosball (not corner)
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 0.75);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 8.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 2.0);
    driveArcDistance(SLOW_MOTOR_PERCENT+1.0, FAST_MOTOR_PERCENT, BACKWARD, 6.0);
    driveArcDistance(SLOW_MOTOR_PERCENT+3.0, FAST_MOTOR_PERCENT, BACKWARD, 3.25);
    driveStraightTime(40.0, BACKWARD, 1.0);

    // Drives off of wall
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0);
    checkHeading(90);

    // Drives to foosball corner
    turn(TURN_MOTOR_PERCENT, LEFT, 89);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.0);
    driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 8.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 130);
    driveStraightTime(40.0, BACKWARD, 0.6);

    // Slides foosball counters
    slideFoosball();

    // Drives to claw lever
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 1.0);

    // Flips claw lever
    flipLever();

    // Drives back to pinball ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 6.5);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 12.5);
    checkHeading(0);

    // Drives down pinball ramp
    driveArcDistance(DEFAULT_MOTOR_PERCENT + 3.0, DEFAULT_MOTOR_PERCENT, BACKWARD, 15.5);
    driveArcDistance(SLOW_MOTOR_PERCENT, DEFAULT_MOTOR_PERCENT + 5.0, BACKWARD, 15.5);

    // Drives to final button
    turn(FAST_MOTOR_PERCENT, LEFT, 115.0);
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 12.0);
    turn(FAST_MOTOR_PERCENT, LEFT, 38);

    // Presses final button
    driveStraightTime(FAST_MOTOR_PERCENT, FORWARD, 1.25);

    LCD.WriteLine("Done!");
    return 0;
}
