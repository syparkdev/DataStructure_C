#include "BinaryTreeList.h"
#define NODE_MAXCOUNT 100

Node addNode(Node root, DATA data)
{
	SResult res = SearchNode(root, data);
	Node newNode;
	
	if (res.cur != NULL)
	{
		printf("�̹� �ִ� ����Դϴ�.");
		return root;
	}
	newNode = (struct _Node*)malloc(sizeof(struct _Node));
	newNode->data = data;
	newNode->lchild = newNode->rchild = NULL;

	if (res.parent == NULL)
		root = newNode;
	else
	{
		if (res.parent->data < data)
			res.parent->rchild = newNode;
		else
			res.parent->lchild = newNode;
	}
	return root;
}

Node deleteNode(Node root, DATA data)
{
	SResult res = SearchNode(root, data);
	Node newNode;

	if (res.cur == NULL)
	{
		printf("���� ����Դϴ�.");
		return root;
	}
	//������ 0
	if (res.cur->lchild == NULL && res.cur->rchild == NULL)
	{
		if (res.parent == NULL)
			root = NULL;
		else
		{
			if (res.cur == res.parent->lchild)
				res.parent->lchild = NULL;
			else
				res.parent->rchild = NULL;
		}
	}
	//������ 1
	else if (res.cur->lchild == NULL || res.cur->rchild == NULL)
	{
		Node child = (res.cur->lchild != NULL) ? res.cur->lchild : res.cur->rchild;

		if (res.parent == NULL)
			root = NULL;
		else
		{
			if (res.cur == res.parent->lchild)
				res.parent->lchild = child;
			else
				res.parent->rchild = child;
		}
	}
	//������ 2
	else
	{
		Node parent = res.cur, trace = res.cur->lchild;   //trace�� �İ��� ����
		while (trace->rchild != NULL)  //�İ��� ��� ã��
		{
			parent = trace;
			trace = trace->rchild;
		}

		res.cur->data = trace->data;   //cur�� data�� trace�� data�� ��ü

		if (trace == parent->lchild)   //�İ����� �ڽİ� �İ��� �θ� ��ũ
			parent->lchild = trace->lchild;
		else
			parent->rchild = trace->lchild;

		res.cur = trace;               //�İ����� data�� cur�� �ű� �� �İ��ڸ� free�ϱ� ���� res.cur�� ����
	}
	free(res.cur);
	return root;
}

SResult SearchNode(Node cur, char data)
{
	SResult res = { NULL,cur };
	while (res.cur != NULL)
	{
		if (res.cur->data < data)
		{
			res.parent = res.cur;
			res.cur = res.cur->rchild;
		}
		else if (res.cur->data > data)
		{
			res.parent = res.cur;
			res.cur = res.cur->lchild;
		}
		else
			return res;
	}
	return res;
}

DATA getCurData(Node cur)
{
	return cur->data;
}

Node getLeftChild(Node cur)
{
	return cur->lchild;
}

Node getRightChild(Node cur)
{
	return cur->rchild;
}

int isTreeEmpty(Node root)
{
	if (root == NULL)
		return 1;
	else
		return 0;
}

void Inorder(Node root)
{
	if (root->lchild != NULL)
		Inorder(root->lchild);
	printf("%c ", root->data);
	if (root->rchild != NULL)
		Inorder(root->rchild);
}