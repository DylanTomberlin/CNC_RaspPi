/*
 * Dylan Tombelin
 * 7/12/17
 * MotorControls.h
 */
#ifndef MOTORCONTROLS_H
#define MOTORCONTROLS_H

void moveLine(Motor (*motors)[], double newX, double newY, double newZ);
int transToStep(Motor *currentMotor, double distance);

#endif
