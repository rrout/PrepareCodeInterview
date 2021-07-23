#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "globalheader.h"

int _print_t(tree_t *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->data);

    int left  = _print_t(tree->left,  1, offset,                depth + 1, s);
    int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}

void print_t(tree_t *tree)
{
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(tree, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

int listExec()
{
	list_t *list = NULL;
	list_t *list1 = NULL;
	list_t *list2 = NULL;
	list = listInsert(list, 111);
	list = listInsert(list, 211);
	list = listInsert(list, 112);
	list = listInsert(list, 311);
	list = listInsert(list, 113);
	list = listInsert(list, 511);
	list = listInsert(list, 115);
	list = listInsert(list, 811);
	list = listInsert(list, 1110);
	
	listPrint(list);
	listPrintREC(list);

	list = listDelete(list, 1110);
	listPrint(list);
	list = listDelete(list, 1110);
	listPrint(list);

	list = listReverse(list);
	listPrint(list);

	list = listReverse(list);
	listPrint(list);

	list = listReverseREC(list);
	listPrint(list);

	list = listInsert(list, 1110);
	listPrint(list);
	list_t *tmp = listMiddle(list);
	std::cout << "listMiddle = " << ((tmp)?tmp->data:0) << std::endl;

	std::cout << "listCount : " << listCount(list) << std::endl;
	std::cout << "listCountREC : " << listCountREC(list) << std::endl;

	std::cout << "listCompare : " << listCompare(list, tmp) << std::endl;
	std::cout << "listCompare : " << listCompare(list, list) << std::endl;

	std::cout << "listCompareREC : " << listCompareREC(list, tmp) << std::endl;
	std::cout << "listCompareREC : " << listCompareREC(list, list) << std::endl;

	std::cout << "listIsSorted : " << listIsSorted(list) << std::endl;
	std::cout << "listIsSortedREC : " << listIsSortedREC(list) << std::endl;

	list = listBubbleSort(list);
	listPrint(list);
	std::cout << "llistBubbleSort istIsSortedREC : " << listIsSortedREC(list) << std::endl;

	list = listSelectSort(list);
	listPrint(list);
	std::cout << "llistSelectSort istIsSortedREC : " << listIsSortedREC(list) << std::endl;

	tmp = listFindDup(list);
	std::cout << "listFindDup = " << ((tmp)?tmp->data:0) << std::endl;
	list = listInsert(list, 1110);
	tmp = listFindDup(list);
	std::cout << "listFindDup = " << ((tmp)?tmp->data:0) << std::endl;

	tmp = listCopy(list);
	listPrint(tmp);
	listPrint(list);
	tmp = listDelete(tmp);
	listPrint(tmp);

	tmp = listCopyREC(list);
	listPrint(tmp);
	listPrint(list);
	tmp = listDelete(tmp);
	listPrint(tmp);

	tmp = listFindNthNode(list, 5);
	std::cout << "listFindNthNode = " << ((tmp)?tmp->data:0) << std::endl;
	tmp = listFindNthNode(list, 55);
	std::cout << "listFindNthNode = " << ((tmp)?tmp->data:0) << std::endl;

	tmp = listFindNthNodeFromEnd(list, 5);
	std::cout << "listFindNthNodeFromEnd (" << 5 << ") = " << ((tmp)?tmp->data:0) << std::endl;
	tmp = listFindNthNodeFromEnd(list, 55);
	std::cout << "listFindNthNodeFromEnd (" << 55 << ") = " << ((tmp)?tmp->data:0) << std::endl;

	tmp = listFindLoop(list);
	std::cout << "listFindLoop = " << ((tmp)?tmp->data:0) << std::endl;

	listPrint(list);
	list1 = list2 = NULL;
	list = listSpiltAlternate(list, &list1, &list2);
	std::cout << "list" << std::endl;
	listPrint(list);
	std::cout << "list1" << std::endl;
	listPrint(list1);
	std::cout << "list2" << std::endl;
	listPrint(list2);
	std::cout << "Merging list1 and list2" << std::endl;
	list = listMergeAlternate(list1, list2);
	listPrint(list);

	tmp = listFindIntersect(list1, list2);
	std::cout << "listFindIntersect = " << ((tmp)?tmp->data:0) << std::endl;

	list1 = list2 = NULL;
	list = listSpiltAlternate(list, &list1, &list2);
	std::cout << "list1" << std::endl;
	listPrint(list1);
	std::cout << "list2" << std::endl;
	listPrint(list2);
	tmp = listFindIntersect(list1, list2);
	std::cout << "listFindIntersect = " << ((tmp)?tmp->data:0) << std::endl;
	std::cout << "Merging list1 and list2 Sorted" << std::endl;
	list = listMergeSorted(list1, list2);
	listPrint(list);

	list = listReverseWithNPair(list, 2);
	listPrint(list);
	list = listReverseAlternateWithNPair(list, 2);
	listPrint(list);

	list = listCircularNShift(list, 2);
	listPrint(list);

	std::cout << "listHasCycle : " << listHasCycle(list) << std::endl;

	list = listRemoveDups(list);
	listPrint(list);

	std::cout << "listMakeAlternateLowHigh : " << std::endl;
	list = listMakeAlternateLowHigh(list);
	listPrint(list);

	list = listSelectSort(list);
	listPrint(list);
	
	list = listSeparateOddEven(list);
	listPrint(list);

	std::cout << "listReverseInRange : " << std::endl;
	list = listReverseInRange(list, 0, 4);
	listPrint(list);

	list = listSwapNthNNode(list, 2);
	listPrint(list);


	return 1;
}
int dlistExec()
{

	return 1;
}
int treeExec()
{
	tree_t *root = NULL;
	tree_t *tmp = NULL;
	tree_t *nu = NULL;
	root = treeInsert(root, 511);
	root = treeInsert(root, 111);
	root = treeInsert(root, 612);
	root = treeInsert(root, 411);
	root = treeInsert(root, 113);
	root = treeInsert(root, 511);
	root = treeInsert(root, 115);
	root = treeInsert(root, 811);
	root = treeInsert(root, 1110);

	treeTraverseInOrderREC(root);
	std::cout << std::endl;
	treeTraverseInOrderRECGRAPH(root, 0);

	std::cout << "treeBstIsBalanced : " << treeBstIsBalanced(root) << std::endl;
	std::cout << "treeIsBstREC = " <<  treeIsBstREC(root) << std::endl;

	root = treeDeleteREC(root);
	treeTraverseInOrderRECGRAPH(root, 0);

	int arr[] = {511, 111, 612, 411, 113, 515, 115, 811, 1110};
	root = treeBstCreateFromArrayREC(arr, sizeof(arr)/sizeof(arr[0]));
	treeTraverseInOrderREC(root);
	std::cout << std::endl;
	treeTraverseInOrderRECGRAPH(root, 0);

	std::cout << "treeHeight : " << treeHeight(root) << std::endl;
	std::cout << "treeHeightREC : " << treeHeightREC(root) << std::endl;

	std::cout << "treeBstIsBalanced : " << treeBstIsBalanced(root) << std::endl;
	std::cout << "treeBstIsBalancedREC : " << treeBstIsBalancedREC(root) << std::endl;

	std::cout << "treeNodeCount : " << treeNodeCount(root) << std::endl;
	std::cout << "treeNodeCountREC : " << treeNodeCountREC(root) << std::endl;

	std::cout << "treeLeafCount : " << treeLeafCount(root) << std::endl;
	std::cout << "treeLeafCountREC : " << treeLeafCountREC(root) << std::endl;

	tmp = treeBinarySearch(root, 511);
	std::cout << "treeBinarySearch = " << ((tmp)?tmp->data:0) << std::endl;
	tmp = treeBinarySearchREC(root, 511);
	std::cout << "treeBinarySearchREC = " << ((tmp)?tmp->data:0) << std::endl;

	tmp = treeSearchREC(root, 511);
	std::cout << "treeSearchREC = " << ((tmp)?tmp->data:0) << std::endl;

	tmp = treeMaxElement(root);
	std::cout << "treeMaxElement = " << ((tmp)?tmp->data:0) << std::endl;

	tmp = treeMaxElementREC(root);
	std::cout << "treeMaxElementREC = " << ((tmp)?tmp->data:0) << std::endl;

	tmp = treeMinElement(root);
	std::cout << "treeMinElement = " << ((tmp)?tmp->data:0) << std::endl;

	tmp = treeMinElementREC(root);
	std::cout << "treeMinElementREC = " << ((tmp)?tmp->data:0) << std::endl;

	treeTraverseInOrder(root);

	tmp = treeFindLca(root, 411, 1110);
	std::cout << "treeFindLca = " << ((tmp)?tmp->data:0) << std::endl;
	tmp = treeFindLcaREC(root, 111, 115);
	std::cout << "treeFindLcaREC = " << ((tmp)?tmp->data:0) << std::endl;

	treeTraverseLevelOrder(root);
	treeTraverseLevelOrderREC(root);

	std::cout << "treeIsBst = " <<  treeIsBst(root) << std::endl;
	std::cout << "treeIsBstREC = " <<  treeIsBstREC(root) << std::endl;

	tmp = treeCopyCreateREC(root);
	treeTraverseInOrderRECGRAPH(tmp, 0);
	std::cout << "treeIsCopyREC = " <<  treeIsCopyREC(root, tmp) << std::endl;
	tmp = treeDeleteREC(tmp);

	tmp = treeMirrorCreateREC(root);
	treeTraverseInOrderRECGRAPH(tmp, 0);
	std::cout << "treeIsMirrorREC = " <<  treeIsMirrorREC(root, tmp) << std::endl;
	tmp = treeDeleteREC(tmp);

	treeTraverseInOrderRECGRAPH(root, 0);
	root = treeDeleteREC(root, 115);
	treeTraverseInOrderRECGRAPH(root, 0);

	treeTraverseInOrderRECGRAPH(root, 0);
	root = treeDeleteREC(root, 113);
	treeTraverseInOrderRECGRAPH(root, 0);

	tmp = treeCopyCreateREC(root);
	treeDelete(tmp);

	std::cout << "treeNodeCountREC = " <<  treeNodeCountREC(root) << std::endl;
	std::cout << "treeNodeCount = " <<  treeNodeCount(root) << std::endl;
	std::cout << "treeLeafCount = " <<  treeLeafCount(root) << std::endl;
	treeTraversePreOrder(root);
	treeTraversePreOrderREC(root);
	std::cout << std::endl;
	treeTraversePostOrder(root);
	treeTraversePostOrderREC(root);
	std::cout << std::endl;

	tmp = treeBstImbalanceNode(root);
	std::cout << "treeBstImbalanceNode = " << ((tmp)?tmp->data:0) << std::endl;

	root = treeInsert(root, 1610);
	print_t(root);
	tmp = treeBstImbalanceNode(root);
	std::cout << "treeBstImbalanceNode = " << ((tmp)?tmp->data:0) << std::endl;
	root = treeBstBalance(root);
	print_t(root);
	std::cout << "treeBstIsBalancedREC : " << treeBstIsBalancedREC(root) << std::endl;


	root = treeInsert(root, 1910);
	print_t(root);
	tmp = treeBstImbalanceNode(root);
	std::cout << "treeBstImbalanceNode = " << ((tmp)?tmp->data:0) << std::endl;
	root = treeBstBalance(root);
	print_t(root);
	std::cout << "treeBstIsBalancedREC : " << treeBstIsBalancedREC(root) << std::endl;


	root = treeInsert(root, 1010);
	root = treeInsert(root, 1510);
	print_t(root);
	tmp = treeBstImbalanceNode(root);
	std::cout << "treeBstImbalanceNode = " << ((tmp)?tmp->data:0) << std::endl;
	root = treeBstBalance(root);
	print_t(root);
	std::cout << "treeBstIsBalancedREC : " << treeBstIsBalancedREC(root) << std::endl;
	

	nu = NULL;
	nu = treeInsert(nu, 5);
	nu = treeInsert(nu, 1);
	print_t(nu);
	nu = treeInsert(nu, 3);
	print_t(nu);
	tmp = treeBstImbalanceNode(nu);
	std::cout << "treeBstImbalanceNode = " << ((tmp)?tmp->data:0) << std::endl;
	nu = treeBstBalance(nu);
	print_t(nu);
	std::cout << "treeBstIsBalancedREC : " << treeBstIsBalancedREC(nu) << std::endl;

  print_t(root);
  treeBstLeftViewREC(root);
  treeBstLeftView(root);
  
  root = treeConvertMirrorREC(root);
  treeTraverseInOrderRECGRAPH(root, 0);
  root = treeConvertMirrorREC(root);
  treeTraverseInOrderRECGRAPH(root, 0);
  
  root = treeConvertMirror(root);
  treeTraverseInOrderRECGRAPH(root, 0);
  root = treeConvertMirror(root);
  treeTraverseInOrderRECGRAPH(root, 0);
  


	return 1;
}
int stringsExec()
{

	return 1;
}
int bitsExec()
{

	return 1;
}
int main(int argc, char const *argv[])
{
	listExec();
	dlistExec();
	//treeExec();
	stringsExec();
	bitsExec();

	return 0;
}