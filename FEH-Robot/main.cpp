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
    driveArcDistance(RAMP_MOTOR_PERCENT + 5.8, RAMP_MOTOR_PERCENT, BACKWARD, 22.0);
    driveArcDistance(RAMP_MOTOR_PERCENT*1.3, DEFAULT_MOTOR_PERCENT*1.1, BACKWARD, 15.0); //used to both be 1.1

    // Drives to token machine
    turn(TURN_MOTOR_PERCENT, RIGHT, 104);
    driveArcDistance(DEFAULT_MOTOR_PERCENT, FAST_MOTOR_PERCENT, FORWARD, 15.0); // 15.5
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0);
    turn(TURN_MOTOR_PERCENT, LEFT, 30);
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
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.3);
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
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 5.1);
    driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 15.0);

    // Drives down pinball ramp
    driveArcDistance((DEFAULT_MOTOR_PERCENT + 3.0)*1.4, DEFAULT_MOTOR_PERCENT*1.4, BACKWARD, 15.0);
    driveArcDistance(SLOW_MOTOR_PERCENT, DEFAULT_MOTOR_PERCENT, BACKWARD, 19.0);

    // Drives to final button
    turn(FAST_MOTOR_PERCENT, LEFT, 110.0);
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 12.0);
    turn(FAST_MOTOR_PERCENT, LEFT, 40);

    // Presses final button
    driveStraightTime(FAST_MOTOR_PERCENT, FORWARD, 1.25);

    LCD.WriteLine("Done!");
    return 0;
}
