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
#include <FEHRPS.h>

void setBreakpoint(int number) {
    // Prints number to screen and beeps
    LCD.WriteLine(number);
    LCD.WriteLine("Tap to continue");
    Buzzer.Beep();

    // Waits for user to press screen
    float x, y;
    while(!LCD.Touch(&x, &y));
}

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

void startRun(){
    // Initializes RPS
    RPS.InitializeTouchMenu();

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

void dropToken(){
    // Move back arm out of the way
    backServo.SetDegree(35);

    // Turn token arm down
    moveFrontServoArm(FAST_MOTOR_PERCENT, DOWN, 0.6);

    // Turn token arm up
    moveFrontServoArm(FAST_MOTOR_PERCENT, UP, 0.6);

    // Reset back arm
    backServo.SetDegree(0);
}

void playDDR(){
    // Retrieves light color (turning and scanning if necessary)
    LightColor color = detectColor();
    int angle = 0;
    float startTime = TimeNow();
    while(color == NoLight && (TimeNow() - startTime) < 1.0){
        turn(TURN_MOTOR_PERCENT, RIGHT, 1.0);
        color = detectColor();
        angle++;
    }

    // Turns back for consistency
    turn(TURN_MOTOR_PERCENT, LEFT, angle);

    // Logic for red and blue lights
    if (color == RedLight) {
        // Prints color detected
        LCD.WriteLine("RED!");

        // Turns toward red button and presses it
        turn(TURN_MOTOR_PERCENT, RIGHT, 45);
        driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.5);

        // Holds button down for 5 seconds
        driveStraightTime(SLOW_MOTOR_PERCENT, FORWARD, 5.5);

        // Backs up to wall of course for consistency
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 3.0);
        turn(TURN_MOTOR_PERCENT, RIGHT, 92);
        driveStraightTime(40.0, BACKWARD, 1.0);

        // aligns in front of ramp
        driveArcDistance(0.0, 65.0, FORWARD, 3.5);
        driveArcDistance(65.0, 0.0, BACKWARD, 3.94);

    } else {
        // Prints color detected
        if (color == BlueLight) {
            LCD.WriteLine("BLUE!");
        } else {
            LCD.WriteLine("Fatal Error in playDDR().");
        }

        // Drives to blue button
        turn(TURN_MOTOR_PERCENT, LEFT, 55); //47
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 6.25);

        // Turns toward blue button and presses it
        turn(TURN_MOTOR_PERCENT, RIGHT, 100);
        driveStraightTime(DEFAULT_MOTOR_PERCENT+5.0, FORWARD, 1.5);

        // Holds button down for 5 seconds
        driveStraightTime(SLOW_MOTOR_PERCENT, FORWARD, 5.5);

        // Backs away from button
        driveArcDistance(DEFAULT_MOTOR_PERCENT, DEFAULT_MOTOR_PERCENT+1.3, BACKWARD, 8.5);
    }
}

void slideFoosball(){
    // Drives up to foosball counter from wall
    driveStraightDistance(SLOW_MOTOR_PERCENT, FORWARD, 2.75);
    Sleep(0.125);

    // Lowers back servo arm
    backServo.SetDegree(124);
    Sleep(0.5);

    // Drives robot and foosball counter forward
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 9.0);
    Sleep(0.25);

    // Raises back servo arm
    backServo.SetDegree(0);
    Sleep(0.125);
}

void flipLever(){
    // Move back arm out of the way
    backServo.SetDegree(35);

    // Turn toward claw lever
    driveArcDistance(40.5, 0, FORWARD, 2.2);

    // Turn servo to flip claw lever
    moveFrontServoArm(FAST_MOTOR_PERCENT, DOWN, 1.15); // 1.15 is better than 1.25.
    Sleep(0.125);

    // Turn robot to avoid un-flipping the claw lever
    turn(TURN_MOTOR_PERCENT, LEFT, 30);
    Sleep(0.125);

    // Reset servo
    moveFrontServoArm(FAST_MOTOR_PERCENT, UP, 1.15);

    // Reset back arm
    backServo.SetDegree(0);

    // Turn robot to avoid un-flipping the claw lever
    turn(TURN_MOTOR_PERCENT, RIGHT, 30);
}
