/*
 * Project: CNC Router control
 * 	  File: main.c
 * 	Author: Dylan Tomberlin
 * 	  Date: 7/10/17
 */

#include <stdio.h>
#include <wiringPi.h>

#include "motor.h"
#include "MotorControls.h"
#include "globals.h"

#define DELAY 10


int main(void){
	wiringPiSetup();
	char letter;
	
	int motorPins[4] = {8, 9, 7, 15};
	
	//Motor myMotor = {.stepsPerRev = 200, .pins = {8, 9, 7, 15}};
	//setUpPins(myMotor.pins);
	
	Motor myMotor;
	myMotor.pins = motorPins;
	myMotor.stepsPerRev = 200;
	myMotor.currentStep = 0;
	

	setUpPins(&myMotor);
	
	double posX = 0;
	double posY = 0;
	double posZ = 0;
	
	
	moveLine(2, 3, 4);
	while(scanf("%c", &letter) > 0);
	
	int i = 0;
	for (i = 0; i < 200; i++){
		step(&myMotor, CW, &posX);
		delay(DELAY);
	}
	for (i = 0; i < 200; i++){
		step(&myMotor, CCW, &posX);
		delay(DELAY);
	}
	
	freeMotor(&myMotor);
	
	
	while(scanf("%c", &letter) > 0);
	
	return 0;
}
