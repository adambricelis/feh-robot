#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "drive.h"
#include "objects_constants.h"
#include "additional_functions.h"
#include "math.h"

/**
 * Starts run after user to presses LCD and start light turns on.
 */
void startRun(){
    // Prompts user to press LCD to start
    LCD.Clear(WHITE);
    LCD.SetFontColor(BLACK);
    LCD.WriteLine("Press to start.");

    // Waits for user to press LCD
    float x, y;
    while(!LCD.Touch(&x, &y));

    // Waits for start light
    while(colorDetected() != RedLight);

    // Starts run
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);
    LCD.WriteLine("Starting now!");
}

/**
 * Determines the color detected by the CdS cell.
 * @return 0 for no light, 1 for red light, 2 for blue light
 */
LightColor colorDetected(){
    LightColor color;

    // Compares sensor values to LightColor enum values
    if(abs(cds.Value() - RED_LIGHT) < LIGHT_EPSILON){
      color = RedLight;
      LCD.WriteLine("Red");
    }
    else if(abs(cds.Value() - BLUE_LIGHT) < LIGHT_EPSILON){
        color = BlueLight;
        LCD.WriteLine("Blue");
    } else {
        color = NoLight;
        LCD.WriteLine("No light");
    }

    return color;
}
