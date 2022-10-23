#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _Node
{
	char name[20];
	struct _Node* link;
} Node;

Node* InsertNode(Node* pList, char* newname)
{
	Node* newNode, *trace = pList, *prevNode = NULL;

	newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name,newname);
	newNode->link = NULL;

	if (pList == NULL || strcmp(pList->name, newname) > 0)
	{
		newNode->link = pList;
		pList = newNode;
	}
	else
	{
		while (trace != NULL && strcmp(trace->name, newname) < 0)
		{
			prevNode = trace;
			trace = trace->link;
		}
		newNode->link = prevNode->link;
		prevNode->link = newNode;
	}

	return pList;
}

Node* DeleteNode(Node* pList, char* newname)
{
	Node* trace = pList, * prevNode = NULL;

	while (trace != NULL && strcmp(trace->name, newname) != 0)
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

Node* SearchNode(Node* pList, char* newname, int* pIndex)
{
	Node* trace = pList;
	*pIndex = 0;
	while (trace != NULL)
	{
		if (strcmp(trace->name, newname) == 0)
			break;
		trace = trace->link;
		*pIndex += 1;
	}
	return trace;
}

void PrintList(Node* pList)
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
}

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

int main()
{
	Node* pList = NULL, *ptr;
	int index;

	printf("(1) Insert \"볼펜\", \"화이트보드\", \"연필깎이\"\n");
	pList = InsertNode(pList, "볼펜");
	pList = InsertNode(pList, "화이트보드");
	pList = InsertNode(pList, "연필깎이");
	PrintList(pList);

	printf("(2) Search \"화이트보드\"\n");
	ptr = SearchNode(pList, "화이트보드", &index);
	printf("\"%s\"를 [%d]번째에서 찾았습니다.\n\n", ptr->name, index);

	printf("(3) Delete \"볼펜\"\n");
	pList = DeleteNode(pList, "볼펜");
	PrintList(pList);

	pList = FreeList(pList);


	return 0;
}