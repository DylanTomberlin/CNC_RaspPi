/*
 * Dylan Tomberlin
 * 7/12/17
 * MotorControls.c
 */

#include <math.h>
#include <stdio.h>

#include "motor.h"
#include "globals.h"
#include "MotorControls.h"

void moveLine(double newX, double newY, double newZ){
	double totalDistance = sqrt((posX - newX)*(posX - newX) + (posY - newY)*(posY - newY) + (posZ - newZ)*(posZ - newZ));
	double travelTime = feedRate / totalDistance;
	
}

int transToStep(double distance, double travelPerStep){
	return distance / travelPerStep;
}
