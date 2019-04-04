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

float startRun(){
    // Function variables
    float ddrY = -1;
    float x, y;

    // Initializes RPS
    RPS.InitializeTouchMenu();

    // Initializes servos
    backServo.SetMin(650);
    backServo.SetMax(2372);
    backServo.SetDegree(0);

    // Loops to retrieve valid y coordinate
    while (ddrY < 0) {
        // Prompts user to press LCD to record DDR y coordinate
        LCD.Clear(WHITE);
        LCD.SetFontColor(BLACK);
        LCD.WriteLine("Press to store DDR location.");

        // Waits for user to press LCD
        while(!LCD.Touch(&x, &y));
        ddrY = RPS.Y();
    }

    // Prompts user to press LCD to start
    LCD.Clear(WHITE);
    LCD.SetFontColor(BLACK);
    LCD.WriteLine("Press to start.");

    // Waits for user to press LCD
    while(!LCD.Touch(&x, &y));

    // Waits for start light or timeout
    float startTime = TimeNow();
    while(detectColor() != RedLight && (TimeNow() - startTime) < START_TIMEOUT);

    // Starts run
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);
    LCD.WriteLine("Starting now!");

    // Recalibrates initial heading
    checkHeading(315);

    return ddrY;
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

    // Logic for red and blue lights
    if (color == RedLight) {
        // Prints color detected
        LCD.WriteLine("RED!");

        // Navigates to red button
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 2.0);
        checkHeading(180);
        driveArcDistance(FAST_MOTOR_PERCENT, -SLOW_MOTOR_PERCENT, FORWARD, 6.0);
        checkHeading(90);
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, FORWARD, 2.0);
        checkHeading(90);
        turn(TURN_MOTOR_PERCENT, LEFT, 90);
        checkHeading(180);

        // Presses red button
        driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.5);

        // Holds button down for 5 seconds
        driveStraightTime(SLOW_MOTOR_PERCENT, FORWARD, 5.25);

        // Backs away from button
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 4.0);

        // Turns toward final button
        turn(TURN_MOTOR_PERCENT, RIGHT, 90);
        checkHeading(90);

    } else {
        // Prints color detected
        if (color == BlueLight) {
            LCD.WriteLine("BLUE!");
        } else {
            LCD.WriteLine("Fatal error in playDDR().");
        }

        // Presses blue button
        driveStraightTime(DEFAULT_MOTOR_PERCENT, FORWARD, 1.5);

        // Holds button down for 5 seconds
        driveStraightTime(SLOW_MOTOR_PERCENT, FORWARD, 5.25);

        // Backs away from button
        driveStraightDistance(DEFAULT_MOTOR_PERCENT, BACKWARD, 7.5);

        // Turns toward final button
        driveArcDistance(FAST_MOTOR_PERCENT, -SLOW_MOTOR_PERCENT, FORWARD, 6.0);
        checkHeading(90);

        // Drives forward to match red button
    }

    // Consistent ending angle
    checkHeading(90);
}

void slideFoosball(){
    // Drives up to foosball counter from wall
    driveStraightDistance(SLOW_MOTOR_PERCENT, FORWARD, 2.25);
    Sleep(0.25);

    // Lowers back servo arm
    backServo.SetDegree(124);
    Sleep(0.5);

    // Drives robot and foosball counter forward
    driveStraightDistance(FAST_MOTOR_PERCENT, FORWARD, 8.5);
    Sleep(0.25);

    // Raises back servo arm
    backServo.SetDegree(0);
    Sleep(0.125);
}

void flipLever(){
    // Move back arm out of the way
    backServo.SetDegree(35);

    // Turn toward claw lever
    driveArcDistance(DEFAULT_MOTOR_PERCENT + 7.5, OFF_MOTOR_PERCENT, FORWARD, 2.5);
    turn(TURN_MOTOR_PERCENT, RIGHT, 5);

    // Turn servo to flip claw lever
    moveFrontServoArm(FAST_MOTOR_PERCENT, DOWN, 1.15);
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
