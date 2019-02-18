#ifndef DRIVE_H
#define DRIVE_H

#include "objects_constants.h"

void setMotors(float, float);

void stopMotors();

void resetEncoders();

void driveForDistance(float, float);

void turn(float, bool, int);

void driveToCollision(float, bool, bool);

#endif
