#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char const *argv[])
{
	bst_t * root = NULL;
	bst_t * tmp = NULL;
	root = bstInsert(root, 1000);
	root = bstInsert(root, 700);
	root = bstInsert(root, 500);
	root = bstInsert(root, 30);
	root = bstInsert(root, 200);
	root = bstInsert(root, 4000);
	root = bstInsert(root, 600);
	root = bstInsert(root, 800);

	printf("------------------\n");
	bstTraversePreOrder(root);
	printf("------------------\n");
	bstTraverseInOrder(root);
	printf("------------------\n");
	bstTraversePostOrder(root);
	printf("------------------\n");
	bstTraverseInOrderGRAPH(root, 0);

	printf("------------------\n");
	tmp = bstSearch(root, 30);
	if(tmp) printf("bstSearch :  %d\n", tmp->data);

	printf("------------------\n");
	tmp = bstSearchREC(root, 30);
	if(tmp) printf("bstSearchREC  : %d\n", tmp->data);

	printf("------------------\n");
	tmp = bstMaxElement(root);
	if(tmp) printf("bstMaxElement  : %d\n", tmp->data);

	printf("------------------\n");
	tmp = bstMinElement(root);
	if(tmp) printf("bstMinElement  : %d\n", tmp->data);

	printf("------------------\n");
	tmp = bstMaxElementREC(root);
	if(tmp) printf("bstMaxElementREC  : %d\n", tmp->data);

	printf("------------------\n");
	tmp = bstMinElement(root);
	if(tmp) printf("bstMinElementREC  : %d\n", tmp->data);


	printf("------------------\n");
	printf("bstHeight  : %d\n", bstHeight(root));

	printf("------------------\n");
	printf("bstHeightREC  : %d\n", bstHeightREC(root));

	printf("------------------\n");
	bstTraverseAtLevel(root, 3);

	printf("------------------\n");
	bstTraverseLevelOrder(root);

	printf("------------------\n");
	bstTraverseLevelOrderQUEUE(root);

	printf("------------------\n");
	bstLeftView(root);
	return 0;
}