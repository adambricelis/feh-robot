#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include "drive.h"
#include "objects_constants.h"
#include "tasks.h"
#include "additional_functions.h"

/**
 * Starts run after user to presses LCD and start light turns on.
 */
void startRun(){
    // Initializes servos
    frontBackServo.SetMin(728);
    frontBackServo.SetMax(2484);
    frontBackServo.SetDegree(0);

    // Prompts user to press LCD to start
    LCD.Clear(WHITE);
    LCD.SetFontColor(BLACK);
    LCD.WriteLine("Press to start.");

    // Waits for user to press LCD
    float x, y;
    while(!LCD.Touch(&x, &y));

    // Waits for start light or timeout
    float startTime = TimeNow();
    while(detectColor() != RedLight && (TimeNow() - startTime) < START_TIMEOUT);

    // Starts run
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);
    LCD.WriteLine("Starting now!");
}

void dropToken(){

}

void playDDR(){

}

void slideFoosball(){

}

/**
 * Flips the claw lever with the arm mounted on the frontBackServo.
 */
void flipLever(){
    frontBackServo.SetDegree(180);
    Sleep(2.0);
    turn(TURN_MOTOR_PERCENT, LEFT, 15);
    Sleep(1.0);
    frontBackServo.SetDegree(0);
}

void pressFinalButton(){

}
