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
    LCD.Clear(WHITE);
    LCD.SetFontColor(BLACK);
    LCD.WriteLine("Press to start");
    
    waitToStart();
    /*
    For performance test 1, drive to upper level, press lever,
    drive back down
    */

    return 0;
}
