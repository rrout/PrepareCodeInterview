#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>


#ifndef __HEADER_H__
#define __HEADER_H__
typedef struct _list_s {
	int data;
	struct _list_s *next;
}list_t;

typedef struct _tree_s {
	int data;
	struct _tree_s *left;
	struct _tree_s *right;
}tree_t;

list_t *listInsert(list_t * root, int data);
list_t *listDelete(list_t * root, int data);
list_t *listDelete(list_t * root);
list_t *listDeleteREC(list_t *root);
list_t *listMid(list_t *root);
list_t *listReverse(list_t *root);
list_t *listReverseREC(list_t *root);
list_t *listReverseKSets(list_t *root, int k);
list_t *listReverseKSetsREC(list_t *root, int k);
list_t *listReArrange(list_t *root);
list_t *listBubbleSort(list_t *root);
list_t *listSelectSort(list_t *root);
list_t *listInsertSort(list_t *root);
list_t *listFindIntersect(list_t *l1, list_t *l2);
list_t *listFindLoop(list_t *root);
list_t *listMergeSortedLists(list_t *l1, list_t *l2);
list_t *listMergeUnSortedLists(list_t *l1, list_t *l2);


void listPrint(list_t *root);
void listPrintREC(list_t *root);

int listCountNodes(list_t *root);
int listCountNodesREC(list_t *root);

bool listIsSorted(list_t *root);
bool listIsSortedREC(list_t *root, list_t *);
bool listIsPalindrome(list_t *root);


tree_t *treeInsert(tree_t *root, int data);
tree_t *treeInsertREC(tree_t *root, int data);
tree_t *treeRemove(tree_t *root, int data);
tree_t *treeRemoveREC(tree_t *root, int data);
tree_t *treeDelete(tree_t *root);
tree_t *treeDeleteREC(tree_t *root);
tree_t *treeBstMinElem(tree_t *root);
tree_t *treeBstMinElemREC(tree_t *root);
tree_t *treeBstMaxElem(tree_t *root);
tree_t *treeBstMaxElemREC(tree_t *root);
tree_t *treeSearch(tree_t *root, int data);
tree_t *treeSearchREC(tree_t *root, int data);
tree_t *treeBstSearch(tree_t *root, int data);
tree_t *treeBstSearchREC(tree_t *root, int data);
tree_t *treeLca(tree_t *root, int data1, int data2);
tree_t *treeBstLca(tree_t *root, int data1, int data2);
tree_t *treeBstLcaREC(tree_t *root, int data1, int data2);
tree_t *treeCopy(tree_t *root);
tree_t *treeMirrorCopy(tree_t *root);
tree_t *treeConvertCopy(tree_t *root);
tree_t *treeConvertMirrorCopy(tree_t *root);
tree_t *treeInorderSuccessor(tree_t *root);
tree_t *treeInorderSuccessorREC(tree_t *root);
tree_t *treeInorderPredissor(tree_t *root);
tree_t *treeInorderPredissorREC(tree_t *root);
tree_t *treeCreateFromArray(int *arr, int size);
tree_t *treeBstCreateFromArray(int *arr, int size);
tree_t *treeGetDeepImbalanceNode(tree_t *root);
tree_t *treeGetDeepImbalanceNodeREC(tree_t *root);

int treeHeight(tree_t *root);
int treeHeightREC(tree_t *root);
int treeNodeCount(tree_t *root);
int treeNodeCountREC(tree_t *root);
int treeLeafCount(tree_t *root);
int treeLeafCountREC(tree_t *root);

void treePrintPreOrder(tree_t *root);
void treePrintPreOrderREC(tree_t *root);
void treePrintInOrder(tree_t *root);
void treePrintInOrderREC(tree_t *root);
void treePrintPostOrder(tree_t *root);
void treePrintPostOrderREC(tree_t *root);
void treePrintInOrderGRAPH(tree_t *root, int n);
void treePrintLevelOrder(tree_t *root);
void treePrintLevelOrderREC(tree_t *root);
void treePrintLeftView(tree_t *root);
void treePrintLeftViewREC(tree_t *root);
void treePrintRightView(tree_t *root);
void treePrintRightViewREC(tree_t *root);

bool treeIsBst(tree_t *root);
bool treeIsBstREC(tree_t *root);
bool treeIsHeightBalanced(tree_t *root);
bool treeIsHeightBalancedREC(tree_t *root);
bool treeIsCopy(tree_t *root);
bool treeIsMirror(tree_t *root);




#endif //__HEADER_H__