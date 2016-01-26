#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "stack.h"
		
typedef struct stack_adt
{
	size_t capacity;
	size_t element_size;
	size_t size;
	void* arr;
}stack_adt;

/* Makes a stadk adt stack_t and return a pointer to it */
stack_t* StackCreate(size_t element_size, size_t num_elements)
{
	stack_t* stack = (stack_t *)malloc(sizeof(stack_adt));
	if(! (stack))
	{
		fprintf(stderr, "error file:%s 	func:%s   line:%d\n", __FILE__, __func__, __LINE__);
		return(NULL);
	}

	stack->capacity = num_elements;
	stack->element_size = element_size;
	stack->size = 0;

	stack->arr = malloc(element_size * num_elements);
	if(! (stack->arr))
	{
		fprintf(stderr, "error file:%s 	func:%s   line:%d\n", __FILE__, __func__, __LINE__);
		return(NULL);
	}
	printf("\n[%s %s %d]\n", __FILE__, __func__, __LINE__); /* DEBUG !!! */
	printf("sizeof(stack_t):%lu\n", sizeof(stack_t));
	return(stack);
}

/*destroy a stack adt */
void StackDestroy(stack_t* stack)
{
	free(stack->arr);
	free(stack);
}
/* removes the top element in the stack */
int StackPop(stack_t* stack)
{
	printf("size before pop:%lu\n", stack->size); 		/* debug !!!!!!!!!!!!!!!!*/
	if(stack->size <= 0)
	{
		return(0); /* nothing to pop */
	}
	else
	{
		--(stack->size);
	}
	printf("size after pop:%lu\n", stack->size); 		/* debug !!!!!!!!!!!!!!!*/

	return(0);
}
/* adds a new_element to the top of the stack */
int StackPush(stack_t* stack, void* new_element)
{
	size_t elem_size_tmp = stack->element_size;
	size_t size_tmp = stack->size;

	char* ptr = &((char*)stack->arr)[elem_size_tmp * size_tmp];

	printf("size before push:%lu\n", stack->size); 		/* debug !!!!!!!!!!!!!!!*/

	if(size_tmp < (stack->capacity))
	{
		memmove(ptr, new_element, elem_size_tmp);
		++(stack->size);
		printf("size after push:%lu\n", stack->size); 		/* debug !!!!!!!!!!!!!!!*/

		return(0); 
	}
	else
	{
		return(-1);

	}
	

	return(0);	
}
/* returns the address of the top element */
void* StackPeep(const stack_t* stack)
{
	void* tmp = (void*)&((char*)stack->arr)[stack->size * stack->element_size];
	printf("peep address:%p\n", tmp);

	return(tmp);
}
/* return the number of elements in the stack */
size_t StackSize(const stack_t* stack)
{
	printf("size StackSize:%lu\n", stack->size); 		/* debug !!!!!!!!!!!!!!!*/

	return(stack->size);
}

