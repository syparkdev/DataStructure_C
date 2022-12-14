#include <stdio.h>
#include "heaptree.h"

void InsertHeap(Heap* pH, Edge item)
{
	int cur;

	if (pH->cnt >= (MAX_COUNT - 1))
	{
		printf("Heap is full\n");
		return;
	}

	pH->data[++pH->cnt] = item;
	cur = pH->cnt;

	while (cur > 1 && pH->data[cur / 2].value < pH->data[cur].value)
	{
		Edge temp = pH->data[cur / 2];
		pH->data[cur / 2] = pH->data[cur];
		pH->data[cur] = temp;
		cur /= 2;
	}
}

Edge DeleteHeap(Heap* pH)
{
	Edge topdata = pH->data[1], temp;
	Edge edge = { 0 };
	int cur = 1;

	if (pH->cnt == 0)
	{
		printf("Heap is empty\n");
		return edge;
	}

	pH->data[1] = pH->data[pH->cnt];
	pH->cnt--;

	while (cur * 2 <= pH->cnt)
	{
		int child = cur * 2;
		//오른쪽 자식이 있다 && 오른쪽 자식이 왼쪽 자식보다 크다
		if ((child + 1) <= pH->cnt && 
			pH->data[child].value < pH->data[child + 1].value)
			child++;
		if (pH->data[child].value <= pH->data[cur].value)
			break;
		temp = pH->data[child];
		pH->data[child] = pH->data[cur];
		pH->data[cur] = temp;
		cur = child;
	}
	return topdata;
}

void PrintHeap(Heap* pH)
{
	int i;
	printf("Heap\n[ ");
	for (i = 1; i <= pH->cnt; i++)
	{
		printf("(%d,%d):%d\n", pH->data[i].from, pH->data[i].to, pH->data[i].value);
	}
	printf(" ]\n\n");
}

/*int main()
{
	Heap heap = { 0 };
	element el;
	int i, count;

	InsertHeap(&heap, 54, 99.5);
	InsertHeap(&heap, 47, 99.1);
	InsertHeap(&heap, 20, 88.9);
	InsertHeap(&heap, 32, 78.0);
	InsertHeap(&heap, 40, 50.9);
	InsertHeap(&heap, 7, 77.1);
	PrintHeap(&heap);

	InsertHeap(&heap, 60, 86.9);
	PrintHeap(&heap);

	el = DeleteHeap(&heap);
	printf("      out : (%d,%f)\n", el.id, el.score);	
	PrintHeap(&heap);

	count = heap.cnt;
	for (i = 0; i < count; i++)
	{
		el = DeleteHeap(&heap);
		printf("      out : (%d,%4.2f)\n", el.id, el.score);
	}

	return 0;
}*/