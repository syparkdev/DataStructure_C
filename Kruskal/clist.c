#include "clist.h"

Node* InsertNode(Node* pList, int data, int value)
{
	Node* newNode, *trace = pList, *prevNode = NULL;

	newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->value = value;
	newNode->link = NULL;

	if (pList == NULL || pList->data > data)
	{
		newNode->link = pList;
		pList = newNode;
	}
	else
	{
		while (trace != NULL && trace->data < data)
		{
			prevNode = trace;
			trace = trace->link;
		}
		newNode->link = prevNode->link;
		prevNode->link = newNode;
	}

	return pList;
}

Node* DeleteNode(Node* pList, int data)
{
	Node* trace = pList, * prevNode = NULL;

	while (trace != NULL && trace->data != data)
	{
		prevNode = trace;
		trace = trace->link;
	}
	if (trace != NULL)
	{
		if (prevNode == NULL)
			pList = pList->link;
		else
		{
			prevNode->link = trace->link;
			free(trace);
		}
	}
	return pList;
}

Node* SearchNode(Node* pList, int data, int* pIndex)
{
	Node* trace = pList;
	*pIndex = 0;
	while (trace != NULL)
	{
		if (trace->data == data)
			break;
		trace = trace->link;
		*pIndex += 1;
	}
	return trace;
}

/*void PrintList(Node* pList)
{
	Node* trace = pList;

	printf("List = (");

	while (trace != NULL)
	{
		printf("%s", trace->name);
		trace = trace->link;
		if (trace != NULL)
			printf(", ");
	}
	printf(")\n\n");
}*/

Node* FreeList(Node* pList)
{
	Node* savelink;
	while (pList != NULL)
	{
		savelink = pList->link;
		free(pList);
		pList = savelink;
	}
	return NULL;
}

/*int main()
{
	Node* pList = NULL, *ptr;
	int index;

	printf("(1) Insert \"����\", \"ȭ��Ʈ����\", \"���ʱ���\"\n");
	pList = InsertNode(pList, "����");
	pList = InsertNode(pList, "ȭ��Ʈ����");
	pList = InsertNode(pList, "���ʱ���");
	PrintList(pList);

	printf("(2) Search \"ȭ��Ʈ����\"\n");
	ptr = SearchNode(pList, "ȭ��Ʈ����", &index);
	printf("\"%s\"�� [%d]��°���� ã�ҽ��ϴ�.\n\n", ptr->name, index);

	printf("(3) Delete \"����\"\n");
	pList = DeleteNode(pList, "����");
	PrintList(pList);

	pList = FreeList(pList);


	return 0;
}*/