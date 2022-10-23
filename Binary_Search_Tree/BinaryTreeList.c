#include "BinaryTreeList.h"
#define NODE_MAXCOUNT 100

Node addNode(Node root, DATA data)
{
	SResult res = SearchNode(root, data);
	Node newNode;
	
	if (res.cur != NULL)
	{
		printf("이미 있는 노드입니다.");
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
		printf("없는 노드입니다.");
		return root;
	}
	//차수가 0
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
	//차수가 1
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
	//차수가 2
	else
	{
		Node parent = res.cur, trace = res.cur->lchild;   //trace에 후계자 저장
		while (trace->rchild != NULL)  //후계자 노드 찾기
		{
			parent = trace;
			trace = trace->rchild;
		}

		res.cur->data = trace->data;   //cur의 data를 trace의 data로 교체

		if (trace == parent->lchild)   //후계자의 자식과 후계자 부모를 링크
			parent->lchild = trace->lchild;
		else
			parent->rchild = trace->lchild;

		res.cur = trace;               //후계자의 data를 cur로 옮긴 뒤 후계자를 free하기 위해 res.cur에 대입
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