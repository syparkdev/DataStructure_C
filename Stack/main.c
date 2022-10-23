#include <stdio.h>
#include "stack.h"

int main()
{
	element data;
	PrintStack("초기 스택");
	Push(10); PrintStack("Push(10)");
	Push(20); PrintStack("Push(20)");
	Push(30); PrintStack("Push(30)");
	data = Peek(); PrintStack("Peek()");
	printf("\tPeek data = %d\n", data);
	data = Pop(); PrintStack("Pop()");
	printf("\tPop data = %d\n", data);
	data = Pop(); PrintStack("Pop()");
	printf("\tPop data = %d\n", data);
	Push(40); PrintStack("Push(40)");
	data = Pop(); PrintStack("Pop()");
	printf("\tPop data = %d\n", data);

	return 0;
}