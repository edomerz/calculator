/*
	calculator
*/
	
#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <stdio.h>

/*
 Recieves a valid (string) mathematical expresison,
Returns the result of the calculations, or NaN if failed. 
str is up to 128 chars
*/
double Calculate(const char *str); 

int IsNaN(double num);

#endif /* ifndef __CALCULATOR_H__*/
