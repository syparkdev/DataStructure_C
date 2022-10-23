
#define MAX_COUNT 100

typedef struct _Edge
{
	int from, to, value;
} Edge;

typedef struct
{
	Edge data[MAX_COUNT];
	int cnt;
} Heap;

void InsertHeap(Heap* pH, Edge item);

Edge DeleteHeap(Heap* pH);

void PrintHeap(Heap* pH);