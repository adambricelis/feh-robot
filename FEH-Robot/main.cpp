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
        //for the whole course
        startRun();

        // Drives to pinball ramp
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 4.0);
        turn(TURN_MOTOR_PERCENT, RIGHT, 45);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 17.5);
        turn(TURN_MOTOR_PERCENT, RIGHT, 85);

        // Drives up pinball ramp
        driveArcDistance(RAMP_MOTOR_PERCENT + 6.0, RAMP_MOTOR_PERCENT, BACKWARD, 22.0);
        driveArcDistance(RAMP_MOTOR_PERCENT, DEFAULT_MOTOR_PERCENT, BACKWARD, 15.0);

        // Drives to token machine
        turn(TURN_MOTOR_PERCENT, RIGHT, 100);
        driveArcDistance(DEFAULT_MOTOR_PERCENT, FAST_MOTOR_PERCENT, FORWARD, 14.5);
        turn(TURN_MOTOR_PERCENT, LEFT, 35);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0);

        // Drops token
        dropToken();

        // Drive to foosball
        //driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 5.0);
        driveArcDistance(SLOW_MOTOR_PERCENT+4, FAST_MOTOR_PERCENT, BACKWARD, 14.0);
        driveArcDistance(SLOW_MOTOR_PERCENT-5, FAST_MOTOR_PERCENT, BACKWARD, 3.0);
        //driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 5.0);
        driveStraightTime(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.0);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0);
        turn(TURN_MOTOR_PERCENT, LEFT, 89);


        //driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 5.5);
        setBreakpoint(1);
        driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 10.0);
        setBreakpoint(2);
        turn(TURN_MOTOR_PERCENT, RIGHT, 110);
        setBreakpoint(3);
        driveArcTime(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 1.125);
        setBreakpoint(4);

        // slides foosball disks
        slideFoosball();

        // Flips claw lever
        //flipLever();

        // END PT 3 CODE

        LCD.WriteLine("Done!");
        return 0;
}
