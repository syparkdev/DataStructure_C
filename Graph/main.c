#include <stdio.h>
#define MAX_VERTICES 10

typedef struct _Node
{
	int data;
	struct _Node* link;
} Node;

typedef struct _Graph
{
	Node* vertices[MAX_VERTICES];
	int count;
} Graph;

void InitGraph(Graph* pGraph)
{
	int i;
	pGraph->count = 0;
	for (i = 0; i < MAX_VERTICES; i++)
		pGraph->vertices[i] = 0;
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
	InsertEdge(&graph, 1, 3);
	InsertEdge(&graph, 1, 2);
	InsertEdge(&graph, 1, 0);

	InsertEdge(&graph, 2, 3);
	InsertEdge(&graph, 2, 1);

	InsertEdge(&graph, 3, 4);
	InsertEdge(&graph, 3, 2);
	InsertEdge(&graph, 3, 1);
	InsertEdge(&graph, 3, 0);

	InsertEdge(&graph, 4, 3);
	InsertEdge(&graph, 4, 1);

	PrintGraph(&graph);

	return 0;
}