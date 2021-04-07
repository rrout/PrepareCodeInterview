#include <stdio.h>
#include <stdlib.h>

typedef struct ibst_s {
	int data;
	ibst_s *left;
	ibst_s *right;
}ibst_t;

ibst_t *ibstInsert(ibst_t *root, int data);
ibst_t *ibstTravreseIn(ibst_t *root);
ibst_t *ibstDelete(ibst_t *root, int data);
ibst_t *ibstSearch(ibst_t *root, int data);
ibst_t *ibstMin(ibst_t *root);
ibst_t *ibstMax(ibst_t *root);


















ibst_t *ibstFromArray(ibst_t *root, int *arr, int start, int end);
ibst_t *ibstFromArray(ibst_t *root, int *arr, int arrSize);
bool ibstIsBST(ibst_t *root);
ibst_t *ibstLCAnonBST(ibst_t *root, int data1, int data2);
ibst_t * ibstIinorderPredecessor(ibst_t *root, int data);
ibst_t * ibstIinorderPredecessor1(ibst_t *root, int data);
ibst_t *ibstIinorderSuccessor(ibst_t *root, int data);
ibst_t * ibstLCA(ibst_t *root, int data1, int data2);
ibst_t * ibstNthElementAscending(ibst_t *root, int n, int *count);
ibst_t *ibstNthElementDescending(ibst_t *root, int n, int *count);