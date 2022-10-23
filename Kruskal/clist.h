#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct _Node
{
	int data;
	int value;
	struct _Node* link;
} Node;

Node* InsertNode(Node* pList, int data, int value);

Node* DeleteNode(Node* pList, int data);

Node* SearchNode(Node* pList, int data, int* pIndex);
