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
#include "debug.h"

#define DELAY 10

	double posX = 2.0;
	double posY = 0;
	double posZ = 0;
	
	double feedRate = 4;

int main(void){
	wiringPiSetup();

	int motorPins[4] = {7, 15, 16, 1};
	Motor myMotor = {.stepsPerRev = 200, .pins = motorPins, .currentStep = 0};
	setUpPins(&myMotor);
	

	
	//step(&myMotor, CW, &posX);
	//step(&myMotor, CW, &posX);
	
	speedTest(&myMotor);
	
	
	//moveLine(2, 3, 4);
	//wait();
	
	//int i = 0;
	/*
	for (i = 0; i < 200; i++){
		step(&myMotor, CW, &posX);
		delay(DELAY);
	}
	for (i = 0; i < 200; i++){
		step(&myMotor, CCW, &posX);
		delay(DELAY);
	}
	*/
	freeMotor(&myMotor);
	
	wait();
	return 0;
}




