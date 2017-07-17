/*
 * debug.h
 * Dylan Tomberlin
 * 7/14/17
 * 
 * Debug and test suite
 */
 
#include <stdio.h>

#include "motor.h"
#include "globals.h"
 
void printArray(int *myArray, int size){

	int i = 0;
	
	printf("[");
	for(i = 0; i < size - 1; i++){
		printf("%d, ", myArray[i]);
	}
	printf("%d]", myArray[size -1]);
}

void wait(void){
	char letter;
	while(scanf("%c", &letter) > 0);
}

void oneRev(Motor *currentMotor, int waitFor){
	int i = 0;
	for(i = 0; i < 200; i++){
		step(currentMotor, CW, &posX);
		delayMicroseconds(waitFor);
	}
}

void speedTest(Motor *currentMotor){
	int i = 50;
	/*for(i = 50; i > 0; i -= 10){
		oneRev(currentMotor, i);
		int rpm = 600 / i;
		printf("Last RPM: %d", rpm);
		wait();
	}*/
	for(i = 10000; i > 0; i -= 500){
		oneRev(currentMotor, i);
		int rpm = 600000 / i;
		printf("Last RPM: %d", rpm);
		wait();
	}
	/*
	for(i = 0; i < 10; i++){
		step(currentMotor, CW, &posX);
		wait();
	}
	*/
}
