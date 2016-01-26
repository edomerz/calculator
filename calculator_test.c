#include <stdio.h>
#include <math.h>

#include "calculator.h"

typedef struct exp_test_case
{
	char *expression;
	double result;
}exp_test_case_t;

double Trunc(double n);

int main(int argc, char *argv[])
{
/*	int i;*/
	double calc_res;
	
	exp_test_case_t test_case = {"1 + 3", 4};
	
	calc_res = Calculate(test_case.expression);
	
	printf("calc_res:%f\n", calc_res);
	
	
	return(0);
}

double Trunc(double n)
{
	return( (((int)(n * 100)) / 1.0) / 100.0);
}
