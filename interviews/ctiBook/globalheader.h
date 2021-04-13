#include <stdio.h>
#include <stdlib.h>

using namespace std;
#include <iostream>
#include <stack>
#include <queue>

typedef struct list_s {
	int data;
	list_s *next;
}list_t;
list_t *listInsert(list_t *root, int data);
list_t *listDelete(list_t *root, int data);
list_t *listDelete(list_t *root);
list_t *listPrint(list_t *root);
list_t *listPrintREC(list_t *root);
list_t *listReverse(list_t *root);
list_t *listReverseREC(list_t *root);
list_t *listMiddle(list_t *root);
list_t *listBubbleSort(list_t *root);
list_t *listSelectSort(list_t *root);
list_t *listInsertSort(list_t *root);
list_t *listFindDup(list_t *root);
list_t *listFindLoop(list_t *root);
list_t *listCopy(list_t *root);
list_t *listCopyREC(list_t *root);
list_t *listFindNthNodeFromEnd(list_t *root, int n);
list_t *listFindNthNode(list_t *root, int n);


bool listIsSorted(list_t *root);
bool listIsSortedREC(list_t *root);
bool listCompare(list_t *root1, list_t *root2);
bool listCompareREC(list_t *root1, list_t *root2);

int listCount(list_t *root);
int listCountREC(list_t *root);










typedef struct dlist_s {
	int data;
	dlist_s *prev;
	dlist_s *next;
}dlist_t;
dlist_t *dlistInsert(dlist_t *root, int data);
dlist_t *dlistDelete(dlist_t *root, int data);
dlist_t *dlistDelete(dlist_t *root);
dlist_t *dlistPrint(dlist_t *root);
dlist_t *dlistPrintREC(dlist_t *root);
dlist_t *dlistReverse(dlist_t *root);
dlist_t *dlistReverseREC(dlist_t *root);
dlist_t *listMiddle(dlist_t *root);









typedef struct tree_s {
	int data;
	tree_s *left;
	tree_s *right;
}tree_t;
tree_t *treeInsert(tree_t *root, int data);
tree_t *treeInsertREC(tree_t *root, int data);
tree_t *treeDelete(tree_t *root, int data);
tree_t *treeDeleteREC(tree_t *root, int data);
tree_t *treeDelete(tree_t *root);
tree_t *treeDeleteREC(tree_t *root);
tree_t *treeSearch(tree_t *root, int data);
tree_t *treeSearchREC(tree_t *root, int data);
tree_t *treeBinarySearch(tree_t *root, int data);
tree_t *treeBinarySearchREC(tree_t *root, int data);
tree_t *treeMaxElement(tree_t *root);
tree_t *treeMaxElementREC(tree_t *root);
tree_t *treeMinElement(tree_t *root);
tree_t *treeMinElementREC(tree_t *root);
tree_t *treeFindLca(tree_t *root, int data1, int data2);
tree_t *treeFindLcaREC(tree_t *root, int data1, int data2);
tree_t *treeBstFindLca(tree_t *root, int data1, int data2);
tree_t *treeBstFindLcaREC(tree_t *root, int data1, int data2);
tree_t *treeBstInorderSuccessor(tree_t *root);
tree_t *treeBstInorderSuccessorREC(tree_t *root);
tree_t *treeBstInorderPredissor(tree_t *root);
tree_t *treeBstInorderPredissorREC(tree_t *root);
tree_t *treeMirrorCreate(tree_t *root);
tree_t *treeMirrorCreateREC(tree_t *root);
tree_t *treeCopyCreate(tree_t *root);
tree_t *treeCopyCreateREC(tree_t *root);
tree_t *treeCreateFromArray(int *arr, int size);
tree_t *treeCreateFromArrayREC(int *arr, int size);
tree_t *treeBstCreateFromArray(int *arr, int size);
tree_t *treeBstCreateFromArrayREC(tree_t *root, int *arr, int start, int end);
tree_t *treeBstCreateFromArrayREC(int *arr, int size);


void treeTraversePreOrder(tree_t *root);
void treeTraversePreOrderREC(tree_t *root);
void treeTraverseInOrder(tree_t *root);
void treeTraverseInOrderREC(tree_t *root);
void treeTraversePostOrder(tree_t *root);
void treeTraversePostOrderREC(tree_t *root);
void treeTraverseLevelOrder(tree_t *root);
void treeTraverseLevelOrderREC(tree_t *root);
void treeTraverseInOrderRECGRAPH(tree_t *root, int space);

bool treeIsBst(tree_t *root);
bool treeIsBstREC(tree_t *root);
bool treeBstIsBalanced(tree_t *root);
bool treeBstIsBalancedREC(tree_t *root);
bool treeIsMirror(tree_t *root1, tree_t *root2);
bool treeIsMirrorREC(tree_t *root1, tree_t *root2);
bool treeIsCopy(tree_t *root1, tree_t *root2);
bool treeIsCopyREC(tree_t *root1, tree_t *root2);

int treeHeight(tree_t *root);
int treeHeightREC(tree_t *root);
int treeNodeCount(tree_t *root);
int treeNodeCountREC(tree_t *root);
int treeLeafCount(tree_t *root);
int treeLeafCountREC(tree_t *root);








