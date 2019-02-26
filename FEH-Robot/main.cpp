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
    // BEGIN PT 2 CODE

    startRun();

    // Drives to DDR
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 10.5);
    turn(TURN_MOTOR_PERCENT, RIGHT, 90);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 9.0);
    Sleep(0.25);

    // Plays Dance Dance Robot
    playDDR();

    // Drives to ramp
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 20.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 49);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 5.0);
    turn(TURN_MOTOR_PERCENT, RIGHT, 49);

    // Drives up ramp
    driveStraightDistance(RAMP_MOTOR_PERCENT, FORWARD, 32.0);
    Sleep(0.5);

    // Drives to foosball counters
    driveArcDistance(FAST_MOTOR_PERCENT, -SLOW_MOTOR_PERCENT, FORWARD, 4.7);
    setBreakpoint(1);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 7.0);
    setBreakpoint(2);
    turn(TURN_MOTOR_PERCENT, LEFT, 40);
    setBreakpoint(3);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 10.0);
    setBreakpoint(4);
    turn(TURN_MOTOR_PERCENT, LEFT, 40);
    setBreakpoint(5);
    driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 2.25);

    // END PT 2 CODE

    LCD.WriteLine("Done!");
    return 0;
}
