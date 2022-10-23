#include <stdio.h>
#include "queue.h"

int main()
{
	element data;
	PrintQueue("√ ±‚ ≈•");
	EnQueue(10); PrintQueue("EnQueue(10)");
	EnQueue(20); PrintQueue("EnQueue(20)");
	EnQueue(30); PrintQueue("EnQueue(30)");
	data = PeekQueue(); PrintQueue("PeekQueue()");
	printf("\tPeek data = %d\n", data);
	data = DeQueue(); PrintQueue("DeQueue()");
	printf("\tDeQueue data = %d\n", data);
	data = DeQueue(); PrintQueue("DeQueue()");
	printf("\tDeQueue data = %d\n", data);
	EnQueue(40); PrintQueue("EnQueue(40)");
	data = DeQueue(); PrintQueue("DeQueue()");
	printf("\tDeQueue data = %d\n", data);

	return 0;
}