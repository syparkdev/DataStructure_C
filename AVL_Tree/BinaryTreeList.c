#include "BinaryTreeList.h"
#define NODE_MAXCOUNT 100
#define MAX_DEPTH 20

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

/*           C            B
		 B        ->   A    C
	 A
*/

Node LL_rotate(Node C)
{
	Node B = C->lchild;
	C->lchild = B->rchild;
	B->rchild = C;
	return B;
}

/*   A                     B
		 B        ->    A     C
	         C
*/

Node RR_rotate(Node A)
{
	Node B = A->rchild;
	A->rchild = B->lchild;
	B->lchild = A;
	return B;
}

/*          C             B
		 A        ->   A    C
	        B
*/

Node LR_rotate(Node C)
{
	C->lchild = RR_rotate(C->lchild);
	return LL_rotate(C);
}

/*       A              B
		    C   ->   A    C
	     B
*/

Node RL_rotate(Node A)
{
	A->rchild = LL_rotate(A->rchild);
	return RR_rotate(A);
}

int GetHeight(Node p)
{
	int height, lHeight, rHeight;

	if (p == NULL)
		return 0;

	lHeight = GetHeight(p->lchild);
	rHeight = GetHeight(p->rchild);
	height = (lHeight > rHeight ? lHeight : rHeight);

	return height + 1;
}

int GetBF(Node p)
{
	if (p == NULL)
		return 0;
	return GetHeight(p->lchild) - GetHeight(p->rchild);
}

Node Rebalance(Node pNode)
{
	int bf = GetBF(pNode);     //밸런스 팩터 = 밸런스 인수를 보관할 변수
	if (bf > 1)
	{
		if (GetBF(pNode->lchild) > 0)
			pNode = LL_rotate(pNode);
		else
			pNode = LR_rotate(pNode);
	}
	else if (bf < -1)
	{
		if (GetBF(pNode->rchild) < 0)
			pNode = RR_rotate(pNode);
		else
			pNode = RL_rotate(pNode);
	}
	return pNode;
}

Node addNodeAVL(Node root, DATA data)
{
	Node newNode;
	Node stack[MAX_DEPTH] = { NULL };
	int idxStack = -1;

	SResult res = { NULL, root };
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
			break;

		stack[++idxStack] = res.parent;
	}


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
	//리밸런스
	for (int i = idxStack; i >= 0; i--)
	{
		Node newRoot = Rebalance(stack[i]);
		if (i == 0)
			root = newRoot;
		else
		{
			Node parent = stack[i - 1];

			if (parent->lchild == stack[i])
				parent->lchild = newRoot;
			else
				parent->rchild = newRoot;
		}
	}
	return root;
}