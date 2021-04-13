#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "globalheader.h"

int listExec()
{
	list_t *list = NULL;
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
	treeExec();
	stringsExec();
	bitsExec();

	return 0;
}