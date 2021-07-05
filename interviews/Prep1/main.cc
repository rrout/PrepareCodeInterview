#include "header.h"

int treeExec() {
	tree_t *root = NULL;
	tree_t *root2 = NULL;
	tree_t *tmp = NULL;
	root = treeInsertREC(root, 555);
	root = treeInsertREC(root, 111);
	root = treeInsertREC(root, 1111);
	root = treeInsertREC(root, 11);
	root = treeInsertREC(root, 55);
	root = treeInsertREC(root, 11111);
	root = treeInsertREC(root, 5555);
	root = treeInsertREC(root, 55555);
	root = treeInsertREC(root, 77);
	root = treeInsertREC(root, 777);

	treePrintPreOrderREC(root);
	std::cout << std::endl;
	treePrintInOrderREC(root);
	std::cout << std::endl;
	treePrintPostOrderREC(root);
	std::cout << std::endl;
	treePrintLevelOrderREC(root);
	std::cout << std::endl;
	treePrintInOrderGRAPH(root, 0);
	std::cout << std::endl;

	treePrintPreOrder(root);
	treePrintInOrder(root);
	treePrintPostOrder(root);
	treePrintLevelOrder(root);

	std::cout << "treeHeightREC : " << treeHeightREC(root) << std::endl;
	std::cout << "treeHeight : " << treeHeight(root) << std::endl;
	
	tmp = treeBstMinElem(root);
	std::cout << "treeBstMinElem" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeBstMinElemREC(root);
	std::cout << "treeBstMinElemREC" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeBstMaxElem(root);
	std::cout << "treeBstMaxElem" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeBstMaxElemREC(root);
	std::cout << "treeBstMaxElemREC" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeBstSearch(root, 1111);
	std::cout << "treeBstSearch" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeBstSearchREC(root, 1111);
	std::cout << "treeBstSearchREC" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeBstSearchREC(root, 444);
	std::cout << "treeBstSearchREC" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeBstLca(root, 5555, 55555);
	std::cout << "treeBstLca" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeBstLcaREC(root, 5555, 55555);
	std::cout << "treeBstLcaREC" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	tmp = treeLca(root, 55, 5555);
	std::cout << "treeLca" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;
	
	root = treeInsert(root, 7555);
	treePrintInOrderGRAPH(root, 0);
	std::cout << std::endl;

	tmp = treeCopy(root);
	treePrintInOrderGRAPH(tmp, 0);
	tmp = treeDelete(tmp);
	tmp = treeMirrorCopy(root);
	treePrintInOrderGRAPH(tmp, 0);
	tmp = treeDeleteREC(tmp);
	treePrintInOrderGRAPH(tmp, 0);

	treePrintInOrderGRAPH(root, 0);
	std::cout << "treeIsBst : " << treeIsBst(root) << std::endl;
	std::cout << "treeIsBstREC : " << treeIsBstREC(root) << std::endl;
	
	tmp = treeMirrorCopy(root);
	std::cout << "treeIsBst : " << treeIsBst(tmp) << std::endl;
	std::cout << "treeIsBstREC : " << treeIsBstREC(tmp) << std::endl;
	tmp = treeDeleteREC(tmp);

	std::cout << "treeIsHeightBalancedREC : " << treeIsHeightBalancedREC(root) << std::endl;
	treePrintLeftViewREC(root);
	treePrintLeftView(root);
	treePrintRightView(root);
	treePrintRightViewREC(root);

	std::cout << "treeNodeCount : " << treeNodeCount(root) << std::endl;
	std::cout << "treeNodeCountREC : " << treeNodeCountREC(root) << std::endl;
	std::cout << "treeLeafCount : " << treeLeafCount(root) << std::endl;
	std::cout << "treeLeafCountREC : " << treeLeafCountREC(root) << std::endl;
}
int listExec() {
	list_t *root = NULL;
	list_t *tmp = NULL;
	list_t *temp = NULL;
	root = listInsert(root, 11);
	root = listInsert(root, 111);
	root = listInsert(root, 1111);
	root = listInsert(root, 11111);
	root = listInsert(root, 55);
	root = listInsert(root, 555);
	root = listInsert(root, 5555);
	root = listInsert(root, 55555);
	root = listInsert(root, 77);
	root = listInsert(root, 777);

	listPrint(root);
	listPrintREC(root);

	tmp = listMid(root);
	std::cout << "listMid" << " : " << ((tmp!=NULL) ? (tmp->data) :0) << std::endl;

	std::cout << "--------------------" << std::endl;
	root = listReverse(root);
	listPrintREC(root);
	root = listReverseREC(root);
	listPrintREC(root);
	std::cout << "--------------------" << std::endl;
	root = listReverseKSets(root, 2);
	listPrintREC(root);
	root = listReverseKSets(root, 2);
	listPrintREC(root);
	std::cout << "---------- listReArrange ----------" << std::endl;
	root = listReArrange(root);
	listPrintREC(root);
	std::cout << "---------- listSelectSort ----------" << std::endl;
	root = listSelectSort(root);
	listPrintREC(root);
	std::cout << "--------- listBubbleSort -----------" << std::endl;
	root = listReArrange(root);
	listPrintREC(root);
	root = listBubbleSort(root);
	listPrintREC(root);
	std::cout << "listCountNodes : " << listCountNodes(root) << std::endl;
	std::cout << "listCountNodesREC : " << listCountNodesREC(root) << std::endl;

	std::cout << "listIsSorted : " << listIsSorted(root) << std::endl;
	root = listReArrange(root);
	std::cout << "listIsSortedREC : " << listIsSortedREC(root, NULL) << std::endl;
	std::cout << "--------- NEW LIST -----------" << std::endl;
	tmp = NULL;
	tmp = listInsert(tmp, 5);
	tmp = listInsert(tmp, 5);
	tmp = listInsert(tmp, 5);
	tmp = listInsert(tmp, 5);
	tmp = listInsert(tmp, 5);
	tmp = listInsert(tmp, 5);
	tmp = listInsert(tmp, 5);
	tmp->data = 5;
	tmp->next->data = 55;
	tmp->next->next->data = 555;
	tmp->next->next->next->data = 5555;
	tmp->next->next->next->next->data = 555;
	tmp->next->next->next->next->next->data = 55;
	tmp->next->next->next->next->next->next->data = 5;
	listPrintREC(tmp);
	std::cout << "listIsPalindrome : " << listIsPalindrome(tmp) << std::endl;
	tmp = listDelete(tmp, 5555);
	listPrintREC(tmp);
	std::cout << "listIsPalindrome : " << listIsPalindrome(tmp) << std::endl;
	tmp = listDelete(tmp, 555);
	listPrintREC(tmp);
	std::cout << "listIsPalindrome : " << listIsPalindrome(tmp) << std::endl;
	tmp = listInsert(tmp, 7777);
	listPrintREC(tmp);
	std::cout << "listIsPalindrome : " << listIsPalindrome(tmp) << std::endl;
	root = listBubbleSort(root);
	tmp = listBubbleSort(tmp);
	listPrintREC(root);
	listPrintREC(tmp);

	//root = listMergeSortedLists(root, tmp);
	//root = listMergeUnSortedLists(root, tmp);

/* //intersect
	temp = listMid(root);
	tmp->next->next->next->next->next->next = temp;
	listPrintREC(root);
	listPrintREC(tmp);
	temp = listFindIntersect(root, tmp);
	std::cout << "listFindIntersect" << " : " << ((temp!=NULL) ? (temp->data) :0) << std::endl;
*/
/*
	std::cout << "--------- TMP LOOP LIST -----------" << std::endl;
	listPrintREC(tmp);
	temp = listMid(tmp);
	tmp->next->next->next->next->next->next = temp;
	temp = listFindLoop(tmp);
	std::cout << "listFindLoop" << " : " << ((temp!=NULL) ? (temp->data) :0) << std::endl;
	if (temp)
		temp->next = NULL;
*/
	listPrintREC(root);
	tmp = listDelete(tmp);
	listPrintREC(tmp);



}
int bitsExec() {

}
int main(int argc, char const *argv[])
{
	treeExec();
	//listExec();
	bitsExec();
	return 0;
}
