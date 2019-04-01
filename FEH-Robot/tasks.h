#ifndef TASKS_H
#define TASKS_H

/**
 * Displays breakpoint number, beeps, and pauses execution
 * until the user taps the LCD. For testing purposes only.
 *
 * @param number
 *          number to be displayed when breakpoint is hit
 */
void setBreakpoint(int number);

/**
 * Determines the color detected by the CdS cell.
 *
 * @return 0 for no light, 1 for red light, 2 for blue light
 */
LightColor detectColor();

/**
 * Moves the front servo arm at the given motorPercent in the
 * given direction for the given amount of time in seconds.
 *
 * @param motorPercent
 *          positive percentage at which to set hacked servo
 * @param direction
 *          true if moving arm up, false if moving arm down
 * @param seconds
 *          positive time for hacked servo to move arm
 */
void moveFrontServoArm(float motorPercent, bool direction, float seconds);

/**
 * Starts run after user to presses LCD and start light turns on.
 */
void startRun();

/**
 * Drops the token in the coin slot from the top level of the course.
 */
void dropToken();

/**
 * Plays Dance Dance Robot and presses the correct button.
 */
void playDDR();

/**
 * Lowers the back servo arm to the foosball counter and drives
 * to push the counter forward.
 */
void slideFoosball();

/**
 * Flips the claw lever with the arm mounted on the frontBackServo.
 */
void flipLever();

#endif
