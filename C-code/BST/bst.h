#include <stdio.h>
#include <stdlib.h>
#ifndef __BST_H__
#define __BST_H__
typedef struct _bst_s {
	int data;
	struct _bst_s *left;
	struct _bst_s *right;
}bst_t;

bst_t * bstInsert(bst_t *root, int data);
bst_t * bstDelete(bst_t *root, int data);
bst_t * bstTraversePreOrder(bst_t *root);
bst_t * bstTraverseInOrder(bst_t *root);
bst_t * bstTraversePostOrder(bst_t *root);
bst_t * bstTraverseInOrderGRAPH(bst_t *root, int level);
bst_t * bstTraverseAtLevel(bst_t *root, int level);
bst_t * bstTraverseLevelOrder(bst_t *root);
bst_t * bstSearch(bst_t *root, int data);
bst_t * bstSearchREC(bst_t *root, int data);
bst_t * bstMaxElement(bst_t *root);
bst_t * bstMaxElementREC(bst_t *root);
bst_t * bstMinElement(bst_t *root);
bst_t * bstMinElementREC(bst_t *root);
bst_t * bstCreateCopy(bst_t *root);
bst_t * bstCreateMirror(bst_t *root);

int bstIsBST_1(bst_t *root);
int bstIsBST_2(bst_t *root);
int bstHeight(bst_t *root);
int bstHeightREC(bst_t *root);
int bstIsCopy(bst_t *root1, bst_t *root2);
int bstIsMorror(bst_t *root1, bst_t *root2);


typedef struct _bst_dlist_s {
	bst_t *data;
	struct _bst_dlist_s *prev;
	struct _bst_dlist_s *next;
}bst_dlist_t;
bst_t * bstTraverseLevelOrderQUEUE(bst_t *root);
bst_t * bstFirstNodeAtLevel(bst_t *root, int level, int *print);
bst_t * bstLeftView(bst_t *root);

#endif