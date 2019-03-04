#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHBuzzer.h>
#include "drive.h"
#include "objects_constants.h"
#include "tasks.h"
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

/**
 * Starts run after user to presses LCD and start light turns on.
 */
void startRun(){
    // Initializes servos
    // TODO: change for hacked servo
//    frontServo.SetMin(728);
//    frontServo.SetMax(2484);
//    frontServo.SetDegree(0);
    // TODO: add backServo calibration

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
    // TODO: change to use hacked servo
//    // Turn servo to drop token down
//    frontServo.SetDegree(TOKEN_DOWN_ANGLE);
//    Sleep(1.5);

//    // Reset servo
//    frontServo.SetDegree(0);
}

/**
 * Plays Dance Dance Robot and presses the correct button.
 */
void playDDR(){
    // Retrieves light color
    LightColor color = detectColor();

    // Logic for red and blue lights
    if (color == RedLight) {
        // Prints color detected
        LCD.WriteLine("RED!");

        // Turns toward red button and presses it
        turn(TURN_MOTOR_PERCENT, RIGHT, 45);
        driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.5);

        // Holds button down for 5 seconds
        driveStraightTime(SLOW_MOTOR_PERCENT, FORWARD, 5.5);
        //Sleep(5.5);

        // Backs up to wall of course for consistency
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 3.0);
        turn(TURN_MOTOR_PERCENT, RIGHT, 85);
        driveStraightTime(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.5);
    } else if (color == BlueLight) {
        // Prints color detected
        LCD.WriteLine("BLUE!");

        // Drives to blue button
        turn(TURN_MOTOR_PERCENT, LEFT, 45);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 6.25);

        // Turns toward blue button and presses it
        turn(TURN_MOTOR_PERCENT, RIGHT, 95);
        driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.5);

        // Holds button down for 5 seconds
        driveStraightTime(SLOW_MOTOR_PERCENT, FORWARD, 5.5);
        //Sleep(5.5);

        // Backs away from button
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 8.5);

        // Turns away from wall
        driveArcDistance(RAMP_MOTOR_PERCENT, -SLOW_MOTOR_PERCENT, FORWARD, 4.75);

        // Backs up to wall of course for consistency
        driveStraightTime(DEFAULT_MOTOR_PERCENT, BACKWARD, 1.5);
    } else {
        LCD.WriteLine("Fatal Error in playDDR().");
    }
}

void slideFoosball(){

}

/**
 * Flips the claw lever with the arm mounted on the frontBackServo.
 */
void flipLever(){
    // TODO: change to use hacked servo

//    // Turn servo to flip claw lever
//    frontServo.SetDegree(180);
//    Sleep(2.0);

//    // Turn robot to avoid un-flipping claw lever
//    turn(TURN_MOTOR_PERCENT, LEFT, 15);
//    Sleep(1.0);

//    // Reset servo
//    frontServo.SetDegree(0);
}

void pressFinalButton(){

}
