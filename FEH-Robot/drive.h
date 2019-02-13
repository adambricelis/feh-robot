#ifndef DRIVE_H
#define DRIVE_H

//use gyro, PID ??
void driveStraight(int power);

void driveToCollision(int left, int right, int switchID);

void tankDrive(int left, int right);

#endif
