#include "BinaryTreeArray.h"
#define NODE_MAXCOUNT 100

static DATA s_tree[NODE_MAXCOUNT] = { 0 };

Node makeRoot(DATA data)
{
	s_tree[1] = data;
	return 1;
}

void addNode(char* path, enum Direction direction, DATA data)
{
	Node trace = 1;

	if (s_tree[trace] != *path)   //path가 루트노드의 값과 일치하는지, 즉 path가 루트에서 시작하나 검사
	{
		printf("%c가 없습니다\n", *path);
		return;
	}
	path++;                       //검사를 통과하면 다음 path로 넘어감
	while (*path != '\0')         //path가 끝나면 빠져나가는 while
	{
		if (s_tree[trace * 2] == *path)  //path가 왼쪽으로 진행하나?
			trace = trace * 2;                 //그럼 trace도 path 따라가
		else if (s_tree[trace * 2 + 1] == *path)  //path가 오른쪽으로 진행하나?
			trace = trace * 2 + 1;               //그럼 trace도 path따라가
		path++;                                  //path하나씩 올리면서 null일때까지 반복
	}
	if (direction == left)                       //path끝나고 내려와서, 왼쪽 자식이냐?
		s_tree[trace * 2] = data;                //그럼 왼쪽에 data 입력
	else if(direction == right)                  //오른쪽 자식이냐?
		s_tree[trace * 2 + 1] = data;            //그럼 오른쪽에 data 입력
}

DATA getCurData(Node cur)
{
	return s_tree[cur];
}

Node getLeftChild(Node cur)
{
	return cur * 2;
}

Node getRightChild(Node cur)
{
	return cur * 2 + 1;
}

int isTreeEmpty(Node root)
{
	if (s_tree[root] == 0)
		return 1;
	else
		return 0;
}