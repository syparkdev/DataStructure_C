#include <stdio.h>
#include "stack.h"
#define STACKSIZE	20

typedef int element;
static element s_stack[STACKSIZE];
static int s_top = -1;

void Push(element data)
{
	if (IsStackFull())
	{
		printf("Stack Full\n\n");
		return;
	}
	s_stack[++s_top] = data;
}

element Pop()
{
	if (IsStackEmpty())
	{
		printf("Stack Empty\n\n");
		return;
	}
	return s_stack[s_top--];

}

element Peek()
{
	if (IsStackEmpty())
	{
		printf("Stack Empty\n\n");
		exit(1);
	}
	return s_stack[s_top];

}

int IsStackEmpty()
{
	if (s_top == -1)
		return 1;
	else
		return 0;
}

int IsStackFull()
{
	if (s_top == STACKSIZE - 1)
		return 1;
	else
		return 0;
}

void PrintStack(char* title)
{
	int i;
	printf("%s : ", title);
	for (i = 0; i <= s_top; i++)
		printf("%d ", s_stack[i]);
	printf("\n");

}