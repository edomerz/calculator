#include <stdio.h>
#include <math.h>	
#include "calculator.h"
	
typedef struct exp_test_case	
{	
    char*   expression;	
    double  result;	
}exp_test_case_t;	
	
/*rount to integer towards zero*/	
double Trunc(double num);	
	
int main(int argc, char* argv[])	
{	
	int i;
	double res_calc;
	
	exp_test_case_t  test_case[50] = 
	
                            {"320/8/4", 10},      /*Associative law*/	
                            {"320-8-4", 308},     /*Associative law*/	
                            {"12-3+4",  13},	
                            {"12+3-4",  11},	
                            {"12+3*5",  27},	
                            {"12*3+5",  41},	
                            {"3+7*2",   17},	
                            {"(3+7)*2", 20},	
                            {"3*7+2",   23},	
                            {"2*4^2-1", 31},	
                            {"2*(4+1)-3", 7},	
                            {"2^3^2", 512},	
                            {"2^(3+5)", 256},	
                            {"1-2", -1},	
                            /*  RD11 Tests*/	
                            {"1", 1},              /* single operand */	
                            {"2345", 2345},        /* multi-digit operand */	
                            {"1+1", 2},            /* single operator */	
                            {"1+2-3-4", -4},       /* multipal operators */	
                            {"1-3-4", -6},         /* operator order between equal operatos */	
                            {"33-12", 21},         /* multi-digit calculation */	
                            {"2*3+1", 7},          /* operator order between unequal operators */	
                            {"6+4^2*2+1", 39},     /* multi-path calculation */	
                            {"(123)", 123 },       /* parenthesis on a singled operand */	
                            {"(1+1)", 2},          /* parenthesis on an expresion */	
                            {"((2+1)*3)", 9},      /* parenthesis order */	
                            {"3^2", 9},            /* power */	
                            {"3^2*6", 54},         /* order of power */	
                            {"6*3^2", 54},         /* order of power */	
                            {"(1+1)^3", 8},        /* parenthesis order */	
                            {"(2*(2-3))", -2},     /* parenthesis order */	
                            {"3^(0-2)", 0.11},     /* negative power */	
                            {"1/3", 0.33},         /* results between 0 and 1 */	
                            {"1/3*6", 2},          /* multiplaction of a non-int */	
                            {"1/5/2", 0.10},       /* division of a non-int */	
                            /*{"1/(0-3)", -0.33},     negative division */	
                            {"(3*(3+3)/3)", 6},    /* operator order. */	
                            {"2/3/4/5*100", 3.33}, /* operator order. */	
                            {"2^2^2", 16},         /* multipal powers. */	
                            {"2^(1/3)", 1.25} ,    /* sqrt. */	
                            {"(1/3)^2", 0.11},     /* power of non-int. */	
                            {"((2-4)^3/((2*2)^2*2-30))^2", 16},    /* final exercise. */	
                            {NULL, 0}	
                            };	
	
    for (i = 30; test_case[i].expression; ++i)	
    {	
        res_calc = Calculate(test_case[i].expression);	
        res_calc = Trunc(res_calc * 100.0) / 100.0;	
        printf("Expression# %d: %s = %.2f\n",i+1, test_case[i].expression, res_calc);	
        if (res_calc != test_case[i].result)	
        {	
            printf("                --->Error! expected result: %.2f\n", test_case[i].result);	
        }	
	
    } 	
    return 0;	
}	
	
/*rount to integer towards zero*/	
double Trunc(double num)	
{	
	return (((int)num)/1.0);	
}	

