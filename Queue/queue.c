#include <stdio.h>
#include "queue.h"

typedef int element;
#define QUEUESIZE	20
static element s_queue [QUEUESIZE];
static int s_front = 0, s_rear = 0;

void EnQueue(element data)
{
	if (IsQueueFull())
	{
		printf("Queue Full\n\n");
		return;
	}
	s_rear = (s_rear + 1) % QUEUESIZE;
	s_queue[s_rear] = data;
}

element DeQueue()
{
	if (IsQueueEmpty())
	{
		printf("Queue Empty\n\n");
		exit(1);
	}
	s_front = (s_front + 1) % QUEUESIZE;
	return s_queue[s_front];

}

element PeekQueue()
{
	int newfront;
	if (IsQueueEmpty())
	{
		printf("Queue Empty\n\n");
		exit(1);
	}
	newfront = (s_front + 1) % QUEUESIZE;
	return s_queue[newfront];

}

int IsQueueEmpty()
{
	if (s_front == s_rear)
		return 1;
	else
		return 0;
}

int IsQueueFull()
{
	if ((s_rear + 1) % QUEUESIZE == s_front)
		return 1;
	else
		return 0;
}

void PrintQueue(char* title)
{
	int trace = (s_front + 1) % QUEUESIZE;;
	printf("%s : ", title);
	if (!IsQueueEmpty())
	{
		while (1)
		{
			printf("%d ", s_queue[trace]);
			if (trace == s_rear)
				break;
			trace = (trace + 1) % QUEUESIZE;
		}
	}
	printf("\n");

}