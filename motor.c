/*
 * Project: CNC Router control
 * 	  File: steps.c
 * 	Author: Dylan Tomberlin
 * 	  Date: 7/10/17
 * 
 * This file should be specific to the platform, i.e. for beta this file is specific to the 
 * Raspberry pi. In future versions, this will be for a micro controller's output.
 * 
 * This file handles the exact pin output for each of the 4 possible steps, as well as the
 * setup of the pins for WiringPi.  The pin numbers of the given 2 phase bipolar stepper motor
 * are passed in as an int array.  pins[0] and pins[1] are a pair of signals for one stepper
 * phase, and pins[2] and pins[3] are the pair of signals for the other phase.
 */
#include <wiringPi.h>
#include <stdio.h>

#include "motor.h"

void setUpPins(Motor *currentMotor){
	int i = 0;
	for(i = 0; i < 4; i++){
		pinMode(currentMotor->pins[i], OUTPUT);
	}
}

void step(Motor *currentMotor, int direction, double *position){
	
	//% operator is remainder, not modulo, so can be negative, hence adding 4 assures it will always be positive.
	currentMotor->currentStep = (currentMotor->currentStep + 4 + direction) % 4; 
	*position += ((currentMotor->travelPerRev)/(currentMotor->stepsPerRev));
	
	switch(currentMotor->currentStep){
		case 0:
			digitalWrite(currentMotor->pins[0], LOW);
			digitalWrite(currentMotor->pins[1], HIGH);   
			digitalWrite(currentMotor->pins[2], HIGH);   
			digitalWrite(currentMotor->pins[3], LOW); 
			break;
			
		case 1:
			digitalWrite(currentMotor->pins[0], LOW);   
			digitalWrite(currentMotor->pins[1], HIGH);   
			digitalWrite(currentMotor->pins[2], LOW);   
			digitalWrite(currentMotor->pins[3], HIGH); 
			break;
			
		case 2:
			digitalWrite(currentMotor->pins[0], HIGH);   
			digitalWrite(currentMotor->pins[1], LOW);   
			digitalWrite(currentMotor->pins[2], LOW);   
			digitalWrite(currentMotor->pins[3], HIGH);
			break;
			
		case 3:
			digitalWrite(currentMotor->pins[0], HIGH);
			digitalWrite(currentMotor->pins[1], LOW);
			digitalWrite(currentMotor->pins[2], HIGH);
			digitalWrite(currentMotor->pins[3], LOW);
			break;
	}
}

void freeMotor(Motor *currentMotor){
	int i = 0;
	for(i = 0; i < 4; i++){
		digitalWrite(currentMotor->pins[i], LOW);
	}
}
