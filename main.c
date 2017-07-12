/*
 * Project: CNC Router control
 * 	  File: main.c
 * 	Author: Dylan Tomberlin
 * 	  Date: 7/10/17
 */

#include <stdio.h>
#include <wiringPi.h>

#include "steps.h"

#define STEPS_PER_REV 200
#define DELAY 25

int main(void){
	wiringPiSetup();
	int motorPins[4] = {8, 9, 7, 15};
	
	//Motor myMotor = {.stepsPerRev = 200, .pins = {8, 9, 7, 15}};
	//setUpPins(myMotor.pins);
	
	Motor myMotor;
	myMotor.pins = motorPins;
	myMotor.stepsPerRev = 200;
	
	/*
	setUpPins(myMotor);
	
	while(1 == 1){
		step1(myMotor);
		delay(DELAY);
		step2(myMotor);
		delay(DELAY);
		step3(myMotor);
		delay(DELAY);
		step4(myMotor);
		delay(DELAY);
	}
	*/
	return 0;
}
