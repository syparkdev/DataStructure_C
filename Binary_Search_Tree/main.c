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

	root = addNode(root, 'D');
	root = addNode(root, 'G');
	root = addNode(root, 'B');
	root = addNode(root, 'E');
	root = addNode(root, 'C');
	root = addNode(root, 'A');
	root = addNode(root, 'F');

	Inorder(root); printf("\n");

	res = SearchNode(root, 'E');
	printf("'E': %s parent=%p(%c)\n", 
		(res.cur == NULL) ? "실패" : "성공",
		res.parent, (res.parent == NULL) ? '.' : res.parent->data);

	res = SearchNode(root, 'S');
	printf("'S': %s parent=%p(%c)\n",
		(res.cur == NULL) ? "실패" : "성공",
		res.parent, (res.parent == NULL) ? '.' : res.parent->data);

	root = deleteNode(root, 'D');

	Inorder(root); printf("\n");

	return 0;
}