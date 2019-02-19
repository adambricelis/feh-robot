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

    // Drives up pinball ramp
    // TODO: figure out measurements of pinball ramp
    driveDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 40.0);

    // Drives to claw lever

    // Activates claw lever
    flipLever();

    // Drives back to pinball ramp

    // Drives down pinball ramp

    // Drives back to charging station

    // END PT 1 CODE

    LCD.WriteLine("Done!");
    return 0;
}
