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
    // BEGIN PT 4 CODE

    startRun();

    // Drives to pinball ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 4.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 45);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 17.5);
    turn(TURN_MOTOR_PERCENT, RIGHT, 85);

    // Drives up pinball ramp
    driveArcDistance(RAMP_MOTOR_PERCENT + 6.0, RAMP_MOTOR_PERCENT, BACKWARD, 22.0);

    // Drives to foosball counter
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 13.75);
    driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 10.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 110);
    driveArcTime(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 1.125);

    // Slides foosball counter
    slideFoosball();

    // Drives to pinball ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 4.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 60);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 10.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 25);

    // Drives down pinball ramp
    driveStraightDistance(RAMP_MOTOR_PERCENT, BACKWARD, 15.0);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 18.0);

    // Turns robot around
    turn(TURN_MOTOR_PERCENT + 10, RIGHT, 165);

    // Presses DDR button
    driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.25);
    driveStraightTime(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.0);

    // Drives to final button
    turn(TURN_MOTOR_PERCENT, RIGHT, 80);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 15.0);
    turn(TURN_MOTOR_PERCENT, LEFT, 45);


    // Presses final button
    driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 3.0);



    // END PT 4 CODE

    LCD.WriteLine("Done!");
    return 0;
}
