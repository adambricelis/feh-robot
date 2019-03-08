#ifndef DRIVE_H
#define DRIVE_H

#include "objects_constants.h"

void setMotors(float, float);

void setMotorsWithDirection(float, float, bool);

void stopMotors();

void resetEncoders();

void driveStraightDistance(float, bool, float);

void driveStraightTime(float, bool, float);

void driveArcDistance(float, float, bool, float);

void driveArcTime(float, float, bool, float);

void turn(float, bool, float);

#endif
