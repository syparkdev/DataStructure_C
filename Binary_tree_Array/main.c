#include <stdio.h>
#include "BinaryTreeList.h"

/*Node makeRoot(DATA data);
void addNode(char* path, enum Direction direction, DATA data);
DATA getCurData(Node cur);
Node getLeftChild(Node cur);
Node getRightChild(Node cur);
int isTreeEmpty(Node root);*/

int main()
{
	Node root = makeRoot('-');
	addNode("-", left, '*');
	addNode("-", right, '/');
	addNode("-*", left, 'A');
	addNode("-*", right, 'B');
	addNode("-/", left, 'C');
	addNode("-/", right, 'D');

	printf("root = %c\n", getCurData(root));
	printf("root's left = %c\n", getCurData(getLeftChild(root)));
	printf("root's left's left = %c\n", getCurData(getLeftChild(getLeftChild(root))));
	printf("root's left's right = %c\n", getCurData(getRightChild(getLeftChild(root))));
	printf("root's right = %c\n", getCurData(getRightChild(root)));
	printf("root's right's left = %c\n", getCurData(getLeftChild(getRightChild(root))));
	printf("root's right's right = %c\n", getCurData(getRightChild(getRightChild(root))));

	return 0;
}