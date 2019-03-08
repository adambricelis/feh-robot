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
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 14.0);
    driveArcDistance(FAST_MOTOR_PERCENT, SLOW_MOTOR_PERCENT, BACKWARD, 10.0);
    setBreakpoint(1);
    turn(TURN_MOTOR_PERCENT, RIGHT, 110);
    setBreakpoint(2);
    driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 2.0);
    setBreakpoint(3);
    driveArcTime(SLOW_MOTOR_PERCENT, FAST_MOTOR_PERCENT, BACKWARD, 1.0);
    setBreakpoint(4);

    // Slides foosball counter
    slideFoosball();

    // Drives to pinball ramp

    // Drives down pinball ramp

    // Presses DDR button
    driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.0);
    driveStraightTime(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.0);

    // Drives to final button

    // Presses final button


    // END PT 4 CODE

    LCD.WriteLine("Done!");
    return 0;
}
