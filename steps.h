/*
 * Project: CNC Router control
 * 	  File: steps.h
 * 	Author: Dylan Tomberlin
 * 	  Date: 7/10/17
 */
 
#ifndef STEPS_H
#define STEPS_H
 
 
typedef struct {
	int stepsPerRev;
	float travelPerRev;
	int pins[4];
} Motor;


void setUpPins(Motor currentMotor);

void step1(Motor currentMotor);
void step2(Motor currentMotor);
void step3(Motor currentMotor);
void step4(Motor currentMotor);

#endif
