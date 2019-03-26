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

        // Drives to pinball ramp
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 4.0);
        turn(TURN_MOTOR_PERCENT, RIGHT, 45);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 17.5);
        turn(TURN_MOTOR_PERCENT, RIGHT, 85);

        // Drives up pinball ramp
        driveArcDistance(RAMP_MOTOR_PERCENT + 6.0, RAMP_MOTOR_PERCENT, BACKWARD, 22.0);
        driveArcDistance(RAMP_MOTOR_PERCENT*1.1, DEFAULT_MOTOR_PERCENT*1.1, BACKWARD, 14.0);

        // Drives to token machine
        turn(TURN_MOTOR_PERCENT, RIGHT, 100);
        driveArcDistance(DEFAULT_MOTOR_PERCENT, FAST_MOTOR_PERCENT, FORWARD, 14.5);
        turn(TURN_MOTOR_PERCENT, LEFT, 35);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0);

        // Drops token
        driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.0);
        //driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.2);
        dropToken();
       // driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.0);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.0);

        // Drive to foosball
        driveArcDistance(SLOW_MOTOR_PERCENT+1.0, FAST_MOTOR_PERCENT, BACKWARD, 14.0);
        driveArcDistance(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 3.0);
        driveStraightTime(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.5);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0);
        turn(TURN_MOTOR_PERCENT, LEFT, 89);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 2.1);
        driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 8.0);
        turn(TURN_MOTOR_PERCENT, RIGHT, 138);
        driveStraightTime(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.2);
        driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 0.1);

        // Slides foosball counters
        slideFoosball();

        // Drives to claw lever
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 1.0);

        // Flips claw lever
        flipLever();

        //drive back


        //DDR


        LCD.WriteLine("Done!");
        return 0;
}
