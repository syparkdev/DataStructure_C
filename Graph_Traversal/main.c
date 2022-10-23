#include <stdio.h>
#include <malloc.h>
#include "stack.h"
#include "queue.h"

#define MAX_VERTICES 10

typedef struct _Node
{
	int data;
	struct _Node* link;
} Node;

typedef struct _Graph
{
	Node* vertices[MAX_VERTICES];
	int visited[MAX_VERTICES];
	int count;
} Graph;

void InitGraph(Graph* pGraph)
{
	int i;
	pGraph->count = 0;
	for (i = 0; i < MAX_VERTICES; i++)
	{
		pGraph->vertices[i] = 0;
		pGraph->visited[i] = 0;
	}
}

int AllVisited(Graph* pGraph)
{
	int i;
	for (i = 0; i < pGraph->count; i++)
	{
		if (pGraph->visited[i] == 0)
			return 0;
	}
	return 1;
}

void InsertVertex(Graph* pGraph)
{
	if (pGraph->count >= MAX_VERTICES)
	{
		printf("Graph Full\n");
		return;
	}

	pGraph->count++;
}

void InsertEdge(Graph* pGraph, int from, int to)
{
	Node* pNode = (Node *)malloc(sizeof(Node));
	pNode->data = to;
	pNode->link = pGraph->vertices[from];
	pGraph->vertices[from] = pNode;
}

void PrintGraph(Graph* pGraph)
{
	for (int i = 0; i < pGraph->count; i++)
	{
		printf("정점 %c의 리스트 : ", i + 'A');
		Node* trace = pGraph->vertices[i];
		while (trace != NULL)
		{
			printf("%c ", trace->data + 'A');
			trace = trace->link;
		}
		printf("\n");
	}
}

void DFS(Graph* pGraph, int cur)
{
	printf("%c ", cur + 'A');
	pGraph->visited[cur] = 1;
	while (!AllVisited(pGraph))
	{
		Node *next = pGraph->vertices[cur];
		int found = 0;
		while (next != NULL)
		{
			if (pGraph->visited[next->data] == 0)
			{
				Push(cur);
				cur = next->data;
				printf("%c ", cur + 'A');
				pGraph->visited[cur] = 1;
				next = pGraph->vertices[cur];
				found = 1;
				break;
			}
			next = next->link;
		}
		if (found == 0)
			cur = Pop();
	}
}

void BFS(Graph* pGraph, int cur)
{
	printf("%c ", cur + 'A');
	pGraph->visited[cur] = 1;
	EnQueue(cur);
	while (!AllVisited(pGraph))
	{
		cur = DeQueue();
		Node* next = pGraph->vertices[cur];
		while (next != NULL)
		{
			if (pGraph->visited[next->data] == 0)
			{
				printf("%c ", next->data + 'A');
				pGraph->visited[next->data] = 1;
				EnQueue(next->data);
			}
			next = next->link;
		}
	}	
}

int main()
{
	Graph graph;
	int i;

	InitGraph(&graph);

	for (i = 0; i < 5; i++)
		InsertVertex(&graph, i);

	InsertEdge(&graph, 0, 3);
	InsertEdge(&graph, 0, 1);

	InsertEdge(&graph, 1, 4);
	InsertEdge(&graph, 1, 2);
	InsertEdge(&graph, 1, 0);

	InsertEdge(&graph, 2, 1);

	InsertEdge(&graph, 3, 0);

	InsertEdge(&graph, 4, 1);

	PrintGraph(&graph);

	//printf("\n\n깊이 우선 탐색 : ");
	//DFS(&graph, 0);

	printf("\n\n너비 우선 탐색 : ");
	BFS(&graph, 0);

	return 0;
}

