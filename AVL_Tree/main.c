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
	Node root = NULL;
	SResult res;

	root = addNodeAVL(root, 'A');
	root = addNodeAVL(root, 'B');
	root = addNodeAVL(root, 'C');
	root = addNodeAVL(root, 'D');
	root = addNodeAVL(root, 'E');
	root = addNodeAVL(root, 'F');
	root = addNodeAVL(root, 'G');

	Inorder(root); printf("\n");

	

	return 0;
}