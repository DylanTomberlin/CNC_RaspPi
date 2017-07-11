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
	int motorPins[4] = {8, 9, 7, 15};
	int i = 0;
	char myChar;
	
	wiringPiSetup();
	setUpPins(motorPins);
	while(1 == 1){
		step1(motorPins);
		delay(DELAY);
		step2(motorPins);
		delay(DELAY);
		step3(motorPins);
		delay(DELAY);
		step4(motorPins);
		delay(DELAY);
	}
	return 0;
}
