/*
 * Project: CNC Router control
 * 	  File: steps.h
 * 	Author: Dylan Tomberlin
 * 	  Date: 7/10/17
 */
 
#ifndef MOTOR_H
#define MOTOR_H

#define CW 1
#define CCW -1 
 
typedef struct{
	int stepsPerRev;
	double travelPerRev;
	int *pins;
	int currentStep;
}Motor;

void setUpPins(Motor *currentMotor);

void step(Motor *currentMotor, int direction, double *position);
void freeMotor(Motor *currentMotor);

#endif
