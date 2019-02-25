#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHBuzzer.h>
#include "drive.h"
#include "objects_constants.h"
#include "additional_functions.h"
#include <math.h>
using namespace std;

/**
 * Displays breakpoint number, beeps, and pauses execution
 * until the user taps the LCD. For testing purposes only.
 *
 * @param number
 *          number to be displayed when breakpoint is hit
 */
void setBreakpoint(int number) {
    // Prints number to screen and beeps
    LCD.WriteLine(number);
    LCD.WriteLine("Tap to continue");
    Buzzer.Beep();

    // Waits for user to press screen
    float x, y;
    while(!LCD.Touch(&x, &y));
}

/**
 * Determines the color detected by the CdS cell.
 * @return 0 for no light, 1 for red light, 2 for blue light
 */
LightColor detectColor(){
    LightColor color;

    // Compares sensor values to LightColor enum values
    if(abs(cds.Value() - RED_LIGHT) < LIGHT_EPSILON){
      color = RedLight;
    }
    else if(abs(cds.Value() - BLUE_LIGHT) < LIGHT_EPSILON){
        color = BlueLight;
    } else {
        color = NoLight;
    }

    return color;
}
