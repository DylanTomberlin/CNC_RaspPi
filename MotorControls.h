/*
 * Dylan Tombelin
 * 7/12/17
 * MotorControls.h
 */
#ifndef MOTORCONTROLS_H
#define MOTORCONTROLS_H

void moveLine(double newX, double newY, double newZ);
int transToStep(double distance, double travelPerStep);

#endif
