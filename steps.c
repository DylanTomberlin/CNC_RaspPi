/*
 * Project: CNC Router control
 * 	  File: steps.c
 * 	Author: Dylan Tomberlin
 * 	  Date: 7/10/17
 * 
 * This file handles the exact pin output for each of the 4 possible steps, as well as the
 * setup of the pins for WiringPi.  The pin numbers of the given 2 phase bipolar stepper motor
 * are passed in as an int array.  pins[0] and pins[1] are a pair of signals for one stepper
 * phase, and pins[2] and pins[3] are the pair of signals for the other phase.
 */
#include <wiringPi.h>

#include "steps.h"

void setUpPins(Motor currentMotor){
	int i = 0;
	for(i = 0; i < 4; i++){
		pinMode(currentMotor.pins[i], OUTPUT);
	}
}

void step1(Motor currentMotor){
	digitalWrite(currentMotor.pins[0], LOW);
	digitalWrite(currentMotor.pins[1], HIGH);   
	digitalWrite(currentMotor.pins[2], HIGH);   
	digitalWrite(currentMotor.pins[3], LOW); 
}

void step2(Motor currentMotor){
	digitalWrite(currentMotor.pins[0], LOW);   
	digitalWrite(currentMotor.pins[1], HIGH);   
	digitalWrite(currentMotor.pins[2], LOW);   
	digitalWrite(currentMotor.pins[3], HIGH); 
}

void step3(Motor currentMotor){
	digitalWrite(currentMotor.pins[0], HIGH);   
	digitalWrite(currentMotor.pins[1], LOW);   
	digitalWrite(currentMotor.pins[2], LOW);   
	digitalWrite(currentMotor.pins[3], HIGH); 
}

void step4(Motor currentMotor){
	digitalWrite(currentMotor.pins[0], HIGH);
	digitalWrite(currentMotor.pins[1], LOW);
	digitalWrite(currentMotor.pins[2], HIGH);
	digitalWrite(currentMotor.pins[3], LOW);
}
