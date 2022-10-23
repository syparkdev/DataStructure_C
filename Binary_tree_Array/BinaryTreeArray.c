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

	if (s_tree[trace] != *path)   //path�� ��Ʈ����� ���� ��ġ�ϴ���, �� path�� ��Ʈ���� �����ϳ� �˻�
	{
		printf("%c�� �����ϴ�\n", *path);
		return;
	}
	path++;                       //�˻縦 ����ϸ� ���� path�� �Ѿ
	while (*path != '\0')         //path�� ������ ���������� while
	{
		if (s_tree[trace * 2] == *path)  //path�� �������� �����ϳ�?
			trace = trace * 2;                 //�׷� trace�� path ����
		else if (s_tree[trace * 2 + 1] == *path)  //path�� ���������� �����ϳ�?
			trace = trace * 2 + 1;               //�׷� trace�� path����
		path++;                                  //path�ϳ��� �ø��鼭 null�϶����� �ݺ�
	}
	if (direction == left)                       //path������ �����ͼ�, ���� �ڽ��̳�?
		s_tree[trace * 2] = data;                //�׷� ���ʿ� data �Է�
	else if(direction == right)                  //������ �ڽ��̳�?
		s_tree[trace * 2 + 1] = data;            //�׷� �����ʿ� data �Է�
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