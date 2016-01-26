#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct stack_adt stack_t;

/* Makes a stadk adt stack_t and return a pointer to it */
stack_t* StackCreate(size_t element_size, size_t num_elements);
/*destroy a stack adt */
void StackDestroy(stack_t* stack);

/* removes the top element in the stack */
int StackPop(stack_t* s);

/* adds a new_element to the top of the stack */
int StackPush(stack_t* stack, void* new_element);


/* returns the address of the top element */
void* StackPeep(const stack_t* stack);

/* return the number of elements in the stack */
size_t StackSize(const stack_t* stack);

#endif /* ifndef __STACK_H__*/ 

