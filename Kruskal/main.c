#include <stdio.h>
#include <malloc.h>
#include "stack.h"
#include "queue.h"
#include "heaptree.h"
#include "clist.h"

#define MAX_VERTICES 10

static Heap s_heap = { 0 };

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

void ClearVisited(Graph* pGraph)
{
	int i;
	for (i = 0; i < MAX_VERTICES; i++)
	{
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

void InsertEdge(Graph* pGraph, int from, int to, int value)
{
	pGraph->vertices[from] = InsertNode(pGraph->vertices[from], to, value);
}

void DeleteEdge(Graph* pGraph, int from, int to)
{
	pGraph->vertices[from] = DeleteNode(pGraph->vertices[from], to);
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

int DFS(Graph* pGraph, int cur)
{
	int cnt = 0;
	ClearVisited(pGraph);
	//printf("%c ", cur + 'A');
	cnt++;
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
				//printf("%c ", cur + 'A');
				cnt++;
				pGraph->visited[cur] = 1;
				next = pGraph->vertices[cur];
				found = 1;
				break;
			}
			next = next->link;
		}
		if (found == 0)
		{
			if (IsStackEmpty())
				break;
			else 
				cur = Pop();
		}
	}
	while (!IsStackEmpty())
		Pop();
	return cnt;
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

int Kruskal(Graph* pGraph, int value)
{
	while (1)
	{
		int cnt_1, cnt_2;
		Edge edge = DeleteHeap(&s_heap);

		if (edge.value == 0)
			break;

		cnt_1 = DFS(pGraph, edge.from);            		//현재의 연결 요소 개수
		DeleteEdge(pGraph, edge.to, edge.from);         //간선 삭제
		DeleteEdge(pGraph, edge.from, edge.to);
		cnt_2 = DFS(pGraph, edge.from);


		if (cnt_1 > cnt_2)
		{
			InsertEdge(pGraph, edge.to, edge.from, edge.value);
			InsertEdge(pGraph, edge.from, edge.to, edge.value);
		}
		else
		{
			value -= edge.value;
		}
	} 
	return value;
}

int main()
{
	Graph graph;
	int i, value = 0;

	InitGraph(&graph);

	for (i = 0; i < 5; i++)
		InsertVertex(&graph);

	InsertEdge(&graph, 0, 1, 7);
	InsertEdge(&graph, 0, 2, 3);
	InsertEdge(&graph, 0, 3, 5);

	InsertEdge(&graph, 1, 0, 7);
	InsertEdge(&graph, 1, 3, 10);
	InsertEdge(&graph, 1, 4, 2);

	InsertEdge(&graph, 2, 0, 3);
	InsertEdge(&graph, 2, 3, 4);

	InsertEdge(&graph, 3, 0, 5);
	InsertEdge(&graph, 3, 1, 10);
	InsertEdge(&graph, 3, 2, 4);
	InsertEdge(&graph, 3, 4, 6);

	InsertEdge(&graph, 4, 1, 2);
	InsertEdge(&graph, 4, 3, 6);

	PrintGraph(&graph);

	{
		Edge edges[] =
		{
			{0, 1, 7},
			{0, 3, 5},
			{0, 2, 3},
			{2, 3, 4},
			{1, 3, 10},
			{1, 4, 2},
			{3, 4, 6}
		};
		
		int cnt = sizeof(edges) / sizeof(edges[0]), i;
		for (i = 0; i < cnt; i++)
		{
			InsertHeap(&s_heap, edges[i]);
			value += edges[i].value;
		}
	}

	printf("최소비용 = %d \n", Kruskal(&graph, value));

	PrintGraph(&graph);

	return 0;
}

