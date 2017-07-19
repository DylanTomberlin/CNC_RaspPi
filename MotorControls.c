/*
 * Dylan Tomberlin
 * 7/12/17
 * MotorControls.c
 */

#include <math.h>
#include <stdio.h>
//#include <stdbool.h>
#include <wiringPi.h>

#include "motor.h"
#include "globals.h"
#include "MotorControls.h"

void moveLine(Motor (*motors)[], double newX, double newY, double newZ){
	int xCount = 0;
	int yCount = 0;
	int zCount = 0;
	
	int xFinal = transToStep(motors[MOTORX], newX);
	
	double totalDistance = sqrt((posX - newX)*(posX - newX) + (posY - newY)*(posY - newY) + (posZ - newZ)*(posZ - newZ));
	double travelTime = feedRate / totalDistance;
	
	int i = 0;
	//while(!finalX && !finalY && !finalZ){//potential problem if one dimension overshoots 
		//delay(incrementDelay);
	//}
}

int transToStep(Motor *currentMotor, double distance){
	return distance / (currentMotor->travelPerRev / currentMotor->stepsPerRev);
}
