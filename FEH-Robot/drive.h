#ifndef DRIVE_H
#define DRIVE_H

#include "objects_constants.h"

void setMotors(float, float);

void setMotorsWithDirection(float, float, bool);

void stopMotors();

void resetEncoders();

void driveDistance(float, bool, float);

void turn(float, bool, int);

void driveToCollision(float, bool, bool);

#endif
