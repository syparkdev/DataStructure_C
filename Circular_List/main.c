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

	printf("\"��\":�տ� ����\n");
	InsertFront('A', "��");
	PrintDeque(); 

	printf("\"���\":�տ� ����\n");
	InsertFront('A', "���");
	PrintDeque();

	printf("\"����\":�ڿ� ����\n");
	InsertRear('B', "����");
	PrintDeque();

	printf("\"����\":�ڿ� ����\n");
	InsertRear('B', "����");
	PrintDeque();

	printf("�տ��� ����\n");
	pNode = DeleteFront();
	printf("del: %c %s\n", pNode->part, pNode->name);
	PrintDeque();
	free(pNode);

	return 0;
}