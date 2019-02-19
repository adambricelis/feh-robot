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
    // BEGIN PT 1 CODE

    startRun();

    // Drives to pinball ramp
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 3.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 45);
    driveToCollision(DEFAULT_MOTOR_PERCENT, FORWARD, HIT_BOTH);
    driveDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.5);
    turn(DEFAULT_MOTOR_PERCENT, LEFT, 90);
    setBreakpoint(1);

    // Drives up pinball ramp to claw lever
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);
    turn(DEFAULT_MOTOR_PERCENT, LEFT, 90);
    driveToCollision(DEFAULT_MOTOR_PERCENT, BACKWARD, HIT_BOTH);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 3.0);
    turn(DEFAULT_MOTOR_PERCENT, LEFT, 45);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 10.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 45);
    driveToCollision(DEFAULT_MOTOR_PERCENT, FORWARD, HIT_BOTH);
    driveDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.5);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 90);
    // TODO: fix this distance or switch to collision
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 15.0);
    setBreakpoint(2);

    // Activates claw lever
    flipLever();
    setBreakpoint(3);

    // Drives back to pinball ramp
    // TODO: fix this distance?
    driveDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 15.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 90);
    driveToCollision(DEFAULT_MOTOR_PERCENT, BACKWARD, HIT_BOTH);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 10.0);
    turn(DEFAULT_MOTOR_PERCENT, LEFT, 45);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 10.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 45);
    driveToCollision(DEFAULT_MOTOR_PERCENT, FORWARD, HIT_BOTH);
    setBreakpoint(4);

    // Drives down pinball ramp and back to charging station
    driveDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.5);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 90);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);
    turn(DEFAULT_MOTOR_PERCENT, RIGHT, 90);
    driveToCollision(DEFAULT_MOTOR_PERCENT, BACKWARD, HIT_BOTH);
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 15.0);
    setBreakpoint(5);

    // END PT 1 CODE

    LCD.WriteLine("Done!");
    return 0;
}
