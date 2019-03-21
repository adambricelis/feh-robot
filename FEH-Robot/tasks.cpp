#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHBuzzer.h>
#include "drive.h"
#include "objects_constants.h"
#include "tasks.h"
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
 * Moves the front servo arm at the given motorPercent in the
 * given direction for the given amount of time in seconds.
 * @param motorPercent
 *          positive percentage at which to set hacked servo
 * @param direction
 *          true if moving arm up, false if moving arm down
 * @param seconds
 *          positive time for hacked servo to move arm
 */
void moveFrontServoArm(float motorPercent, bool direction, float seconds) {
    // Moves servo in given direction
    if (direction) {
        frontServo.SetPercent(-motorPercent);
    } else {
        frontServo.SetPercent(motorPercent);
    }

    // Waits for given amount of time
    Sleep(seconds);

    frontServo.Stop();
}

/**
 * Starts run after user to presses LCD and start light turns on.
 */
void startRun(){
    // Initializes servos
    backServo.SetMin(650);
    backServo.SetMax(2372);
    backServo.SetDegree(0);

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

/**
 * Drops the token in the coin slot from the top level of the course.
 */
void dropToken(){
    // Move back arm out of the way
    backServo.SetDegree(35);

    // Turn token arm down
    moveFrontServoArm(DEFAULT_MOTOR_PERCENT, DOWN, 1.20);

    // Turn token arm up
    moveFrontServoArm(DEFAULT_MOTOR_PERCENT, UP, 1.20);

    // Reset back arm
    backServo.SetDegree(0);
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

/**
 * Lowers the back servo arm to the foosball counter and drives
 * to push the counter forward.
 */
void slideFoosball(){
    // Drives up to foosball counter from wall
    driveStraightDistance(SLOW_MOTOR_PERCENT, FORWARD, 2.125);
    Sleep(0.5);

    // Lowers back servo arm
    backServo.SetDegree(120);
    Sleep(0.5);

    // Drives robot and foosball counter forward
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 8.25);
    Sleep(0.5);

    // Raises back servo arm
    backServo.SetDegree(0);
}

/**
 * Flips the claw lever with the arm mounted on the frontBackServo.
 */
void flipLever(){
    // Turn servo to flip claw lever
    moveFrontServoArm(DEFAULT_MOTOR_PERCENT, DOWN, 2.5);
    Sleep(0.5);

    // Turn robot to avoid un-flipping the claw lever
    turn(TURN_MOTOR_PERCENT, LEFT, 20);
    Sleep(0.5);

    // Reset servo
    moveFrontServoArm(DEFAULT_MOTOR_PERCENT, UP, 2.5);
}
