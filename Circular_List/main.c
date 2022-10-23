#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _CNode
{
	char part;
	char name[20];
	struct _CNode* link;
} CNode;
CNode* g_deque = NULL;

void InsertFront(char part, char *name)
{
	CNode* newNode = (CNode*)malloc(sizeof(CNode));
	newNode->part = part;
	strcpy(newNode->name, name);
	newNode->link = NULL;

	if (g_deque == NULL)
	{
		g_deque = newNode;
		newNode->link = newNode;
	}
	else 
	{
		newNode->link = g_deque->link;
		g_deque->link = newNode;
	}
}

void InsertRear(char part, char* name)
{
	InsertFront(part, name);
	g_deque = g_deque->link;
}

void PrintDeque()
{
	printf("[ ");
	if (g_deque != NULL)
	{
		CNode* trace = g_deque->link;
		while (1)
		{
			printf("(%c,%s) ", trace->part, trace->name);
			if (trace == g_deque)
				break;
			trace = trace->link;
		}
	}
	printf(" ]\n\n");
}

CNode* DeleteFront()
{
	CNode* trace = g_deque->link;
	if (g_deque == trace->link)
	{
		trace = g_deque;
		g_deque = NULL;
	}
	else
		g_deque->link = trace->link;

	return trace;
}

int main()
{
	CNode* pNode;

	printf("\"배\":앞에 삽입\n");
	InsertFront('A', "배");
	PrintDeque(); 

	printf("\"사과\":앞에 삽입\n");
	InsertFront('A', "사과");
	PrintDeque();

	printf("\"상추\":뒤에 삽입\n");
	InsertRear('B', "상추");
	PrintDeque();

	printf("\"오이\":뒤에 삽입\n");
	InsertRear('B', "오이");
	PrintDeque();

	printf("앞에서 삭제\n");
	pNode = DeleteFront();
	printf("del: %c %s\n", pNode->part, pNode->name);
	PrintDeque();
	free(pNode);

	return 0;
}