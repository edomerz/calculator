#include <stdio.h>	
#include <stdlib.h>	
#include <string.h>
#include <assert.h>
#include <math.h>

#include "calculator.h"	
#include "stack.h"	

#define MAX_EVENTS 256

enum states 	
{ 	
	EXPECT_NUM,	
	EXPECT_OP,	
	NUM_STATES	
}current_state;	
	
enum events 	
{ 	
	END_OF_STRING = '\0',
	NUM,
	OPEN_BRACE = '(',
	CLOSE_BRACE = ')',
	POWER = '^',
	DIV = '/',
	MOD = '%',
	MULTY = '*',
	ADD = '+',
	SUB = '-'
}cur_event;	
	
enum priority	
{	
	ADD_SUB 	  = 1,	
	MULTY_DIV_MOD = 2,	
	POW 		  = 3	
};	

/* create a 2 dim array of funcion pointers that gets void and returns void */
void (*state_table [NUM_STATES][MAX_EVENTS]) (void);	

static int CalculatorInit(void);
static void CalculatorFinish(void);
static void CalculatorDoNothing(void);
static void CalculatorReturnResult(void);
static void CalculatorCalcMult(void);
static void CalculatorCalcDiv(void);
static void CalculatorCalcMod(void);
static void CalculatorCalcAdd(void);
static void CalculatorCalcSub(void);
static void CalculatorOpenBrace(void);
static void CalculatorCloseBrace(void);
static void CalculatorPushOpChangeState(void);
static void CalculatorPushNumChangeState(void);
static void CalculatorInvalid(void);


	
	
/*Global Stack Pointers*/	
stack_t *num_stack = NULL;	
stack_t *op_stack = NULL;	
	
/*global string iterator*/	
char *iter = NULL;	

void TableInit(void (*state_table [NUM_STATES][MAX_EVENTS]) (void))
{
	int i = 0;
	int j = 0;
	
	for(; i < NUM_STATES; ++i)
	{
		for(j = 0; j < MAX_EVENTS; ++j)
		{
			state_table[i][j] = CalculatorDoNothing;
		}
	}
	
	state_table[EXPECT_NUM][END_OF_STRING] = CalculatorReturnResult;
	state_table[EXPECT_NUM][NUM]		   = CalculatorPushNumChangeState;
	state_table[EXPECT_NUM][OPEN_BRACE]    = CalculatorOpenBrace;
	state_table[EXPECT_NUM][CLOSE_BRACE]   = CalculatorInvalid;
	state_table[EXPECT_NUM][POWER]		   = CalculatorInvalid;
	state_table[EXPECT_NUM][DIV]		   = CalculatorInvalid;
	state_table[EXPECT_NUM][MOD]		   = CalculatorInvalid;
	state_table[EXPECT_NUM][MULTY]		   = CalculatorInvalid;
	state_table[EXPECT_NUM][ADD]		   = CalculatorInvalid;
	state_table[EXPECT_NUM][SUB]		   = CalculatorInvalid;
	
	state_table[EXPECT_OP][END_OF_STRING] = CalculatorReturnResult;
	state_table[EXPECT_OP][NUM]		 	  = CalculatorInvalid;
	state_table[EXPECT_OP][OPEN_BRACE]    = CalculatorInvalid;
	state_table[EXPECT_OP][CLOSE_BRACE]   = CalculatorCloseBrace;
	state_table[EXPECT_OP][POWER]		  = CalculatorPushOpChangeState;
	state_table[EXPECT_OP][DIV]		   	  = CalculatorPushOpChangeState;
	state_table[EXPECT_OP][MOD]		   	  = CalculatorPushOpChangeState;
	state_table[EXPECT_OP][MULTY]		  = CalculatorPushOpChangeState;
	state_table[EXPECT_OP][ADD]		  	  = CalculatorPushOpChangeState;
	state_table[EXPECT_OP][SUB]		  	  = CalculatorPushOpChangeState;
	
}
	
static int CalculatorInit(void)	
{	
	/* flags if 1st init or not */
	static int init_flag = 0;
	
	
	if(init_flag == 0)
	{
		/* creats stacks for op and num */
		num_stack = StackCreate(sizeof(char), 128);
		assert(num_stack);
		
		printf("num_stack:%p\n", (void*)num_stack);
		
		
		op_stack = StackCreate(sizeof(char), 128);
		assert(op_stack);
		
		printf("op_stack:%p\n", (void*)op_stack);

		init_flag = 1;
		printf("flag:%d\n", init_flag);
		
		/* init the 2 dim function pointer array */
		TableInit(state_table);
	}
	/* register a function to be called at normal process termination */
	/* int atexit(void (*function)(void)); */
	/* return 0 on successe */
	/* in oreder to call INIT and FINISH only once in main */
	atexit(CalculatorFinish);
	
	return(0);
}	

static void CalculatorFinish(void)	
{	
	StackDestroy(num_stack);	
	StackDestroy(op_stack);	
}	
	
static void CalculatorDoNothing(void)	
{	 
	printf("TO DO\n");
	return;	
}	
	
static void CalculatorReturnResult(void)	
{	
	printf("TO DO\n");
}	
	
static void CalculatorCalcMult(void)	
{	
printf("TO DO\n");
}	

static void CalculatorCalcDiv(void)	
{	
	printf("TO DO\n");
}
	
static void CalculatorCalcMod(void)	
{	
printf("TO DO\n");
}	
	
static void CalculatorCalcAdd(void)	
{	
printf("TO DO\n");
}	
	
static void CalculatorCalcSub(void)	
{	
printf("TO DO\n");
}	

static void CalculatorOpenBrace(void)	
{	
printf("TO DO\n");
}	
	
static void CalculatorCloseBrace(void)	
{	
printf("TO DO\n");
}	
	
static void CalculatorPushOpChangeState(void)	
{	
printf("TO DO\n");
}	
	
static void CalculatorPushNumChangeState(void)	
{	
printf("TO DO\n");
}	

static void CalculatorInvalid(void)
{
printf("TO DO\n");
	CalculatorCalcSub();
	CalculatorCalcAdd();
	CalculatorCalcMod();
	CalculatorCalcDiv();
	CalculatorCalcMult();
}
	
/* Recieves a valid (string) mathematical expresison,	
Returns the result of the calculations, or NaN if failed. */	
double Calculate(const char *expression)
{
	double tmp = 0;
	char c = 0;
	
	CalculatorInit();
	iter = (char*)expression;
	
	printf("sscanf:%d\n", sscanf(iter, "%lf %c", &tmp, &c));
	
	printf("tmp:%f\n", tmp);
	printf("c:%c\n", c);
	
	StackPush(num_stack,(void*)&tmp);
	
	printf("log10(tmp):%f\n", log10(tmp));
	iter += ((int)(log10(tmp)) + 1);
	printf("\n[%s %s %d]\n", __FILE__, __func__, __LINE__); /* DEBUG !!! */
	printf("iter:%s\n", iter);
	
	
	
	return(1.0);
}
