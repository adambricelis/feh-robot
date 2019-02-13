#include "drive.h"
#include "objects_constants.h"
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>

void driveStraight(float power){
	//gyro, PID??
}

void driveToCollision(float left, float right, int switchID){
        if(switchID == FRONT_LEFT_SW){
		while(microFrontLeft.Value()){
			leftMotor.SetPercent(left);
			rightMotor.SetPercent(right);
		}
	}
        else if(switchID == FRONT_RIGHT_SW){
		while(microFrontRight.Value()){
			leftMotor.SetPercent(left);
			rightMotor.SetPercent(right);
		}
	}
        else if(switchID == BACK_LEFT_SW){
		while(microBackLeft.Value()){
			leftMotor.SetPercent(left);
			rightMotor.SetPercent(right);
		}
	}
        else if(switchID == BACK_RIGHT_SW){
		while(microBackRight.Value()){
			leftMotor.SetPercent(left);
			rightMotor.SetPercent(right);
		}
	}
}

void tankDrive(float left, float right){
	leftMotor.SetPercent(left);
	rightMotor.SetPercent(right);
}
