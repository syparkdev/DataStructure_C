#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef char DATA;
typedef int Node;       //배열의 int값

enum Direction
{
	left, right
};

Node makeRoot(DATA data);
void addNode(char* path, enum Direction direction, DATA data);
DATA getCurData(Node cur);
Node getLeftChild(Node cur);
Node getRightChild(Node cur);
int isTreeEmpty(Node root);