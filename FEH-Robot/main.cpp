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
    setBreakpoint(5);

    // END PT 2 CODE

    LCD.WriteLine("Done!");
    return 0;
}
