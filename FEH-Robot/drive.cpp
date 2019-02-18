#include "drive.h"
#include "objects_constants.h"
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>

void tankDrive(float left, float right){
    leftMotor.SetPercent(left);
    rightMotor.SetPercent(right);
}

void driveStraightCount(float power, int counts){
    while(leftEncoder.Counts() + rightEncoder.Counts() / 0.2 < counts){
        tankDrive(power, power);
    }
}

void driveToCollision(float left, float right, Switch micro) {
    switch (micro) {
    case FrontLeftSwitch:
        leftMotor.SetPercent(left);
        rightMotor.SetPercent(right);
        while(frontLeftSwitch.Value());
        break;

    case FrontRightSwitch:
        leftMotor.SetPercent(left);
        rightMotor.SetPercent(right);
        while(frontRightSwitch.Value());
        break;

    case BackLeftSwitch:
        leftMotor.SetPercent(left);
        rightMotor.SetPercent(right);
        while(backLeftSwitch.Value());
        break;

    case BackRightSwitch:
        leftMotor.SetPercent(left);
        rightMotor.SetPercent(right);
        while(backRightSwitch.Value());
        break;

    default:
        LCD.WriteLine("Error in driveToCollision");
        break;
    }
}
