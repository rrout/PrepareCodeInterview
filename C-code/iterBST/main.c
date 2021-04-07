#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
#include "ibst.h"

void iprintBinaryArray(int *arr, int start, int end)
{
	int mid = 0;
	if (start > end)
		return;
	mid = (start+end)/2;
	std::cout << arr[mid] << std::endl;
	iprintBinaryArray(arr, start, mid-1);
	iprintBinaryArray(arr, mid+1, end);
}
void iprintBinarySearchArray(int *arr, int size)
{
	sort(arr, arr+size);
	iprintBinaryArray(arr, 0, size-1);
}

int main(int argc, char const *argv[])
{
	ibst_t *tree = NULL, *root = NULL;
	ibst_t *tmp = NULL;
	int count = 0;
	int arr[] = {8, 10, 12, 22, 19, 20, 25};
	tree = ibstInsert(tree, 5);
	tree = ibstInsert(tree, 58);
	tree = ibstInsert(tree, 50);
	tree = ibstInsert(tree, 57);
	tree = ibstInsert(tree, 54);
	tree = ibstInsert(tree, 55);

	ibstTravreseIn(tree);

	tree = ibstDelete(tree, 58);
	ibstTravreseIn(tree);

	iprintBinarySearchArray(arr, 7);

	root = ibstFromArray(root, arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);
	ibstTravreseIn(root);

	std::cout << std::endl << "isBST " << ibstIsBST(root) << std::endl;
	tmp = ibstIinorderPredecessor(root, 25);
	std::cout  << "ibstIinorderPredecessor :  " << (tmp ? tmp->data : 0) << std::endl;

	tmp = ibstIinorderPredecessor1(root, 25);
	std::cout  << "ibstIinorderPredecessor1 :  " << (tmp ? tmp->data : 0) << std::endl;

	tmp = ibstIinorderSuccessor(root, 12);
	std::cout  << "ibstIinorderSuccessor :  " << (tmp ? tmp->data : 0) << std::endl;

	tmp = ibstLCA(root, 12, 22);
	std::cout  << "ibstLCA :  " << (tmp ? tmp->data : 0) << std::endl;

	tmp = ibstLCAnonBST(root, 12, 22);
	std::cout  << "ibstLCAnonBST :  " << (tmp ? tmp->data : 0) << std::endl;

	count = 0;
	tmp = ibstNthElementAscending(root, 2, &count);
	std::cout  << "ibstNthElementAscending :  " << (tmp ? tmp->data : 0) << " count: " << count << std::endl;

	count = 0;
	tmp = ibstNthElementDescending(root, 2, &count);
	std::cout  << "ibstNthElementDescending :  " << (tmp ? tmp->data : 0) << " count: " << count << std::endl;

	tmp = ibstMin(root);
	std::cout  << "ibstMin :  " << (tmp ? tmp->data : 0) << std::endl;

	tmp = ibstMax(root);
	std::cout  << "ibstMax :  " << (tmp ? tmp->data : 0) << std::endl;

	return 0;
}