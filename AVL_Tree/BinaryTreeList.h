#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef char DATA;
typedef struct _Node
{
	struct _Node* lchild;
	DATA data;
	struct _Node* rchild;
} *Node;

typedef struct _SResult
{
	Node parent;
	Node cur;
} SResult;

enum Direction
{
	left, right
};

Node addNode(Node root, DATA data);
Node addNodeAVL(Node root, DATA data);
Node deleteNode(Node root, DATA data);
SResult SearchNode(Node cur, char data);
DATA getCurData(Node cur);
Node getLeftChild(Node cur);
Node getRightChild(Node cur);
int isTreeEmpty(Node root);
void Inorder(Node root);
