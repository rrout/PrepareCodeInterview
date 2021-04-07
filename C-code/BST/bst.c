#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

bst_t * bstInsert(bst_t *root, int data)
{
	if (!root)
	{
		root = (bst_t *)malloc(sizeof(bst_t));
		root->data = data;
		root->left = root->right = NULL;
	} else {
		if(data < root->data){
			root->left = bstInsert(root->left, data);
		} else {
			root->right = bstInsert(root->right, data);
		}
	}
	return root;
}
bst_t * bstDelete(bst_t *root, int data)
{
	bst_t *tmp =NULL;
	if(!root){
		return root;
	}
	if (data < root->data)
	{
		root->left = bstDelete(root->left , data);
	} else if (data > root->data) {
		root->right = bstDelete(root->right , data);
	} else {
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return tmp;
		} else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return tmp;
		} else {
			tmp = bstMinElement(root->right);
			root->data = tmp->data;
			root->right = bstDelete(root->right, tmp->data);
		}
	}
	return root;
}
bst_t * bstTraversePreOrder(bst_t *root)
{
	if(root) {
		printf("%d\t", root->data);
		bstTraversePreOrder(root->left);
		bstTraversePreOrder(root->right);
	}
	return root;
}
bst_t * bstTraverseInOrder(bst_t *root)
{
	if(root) {
		bstTraverseInOrder(root->left);
		printf("%d\t", root->data);
		bstTraverseInOrder(root->right);
	}
	return root;
}
bst_t * bstTraversePostOrder(bst_t *root)
{
	if(root) {
		bstTraversePostOrder(root->left);
		bstTraversePostOrder(root->right);
		printf("%d\t", root->data);
	}
	return root;
}
bst_t * bstTraverseInOrderGRAPH(bst_t *root, int level)
{
	int i;
	if(root) {
		bstTraverseInOrderGRAPH(root->left, level+1);
		for (int i = 0; i < level; ++i)
		{
			printf("      ");
		}
		printf("%d\n", root->data);
		bstTraverseInOrderGRAPH(root->right, level+1);
	}
	return root;
}
/*
Print all elements in a given level/height
*/
bst_t * bstTraverseAtLevel(bst_t *root, int level)
{
	if (!root)
	{
		return root;
	}
	if(level==1){
		printf("%d\n", root->data);
	} else {
		bstTraverseAtLevel(root->left, level-1);
		bstTraverseAtLevel(root->right, level-1);
	}
	return NULL;
}
/*
Print all elements in a given level/height starting from root
*/
bst_t * bstTraverseLevelOrder(bst_t *root)
{
	int i;
	int h = bstHeight(root);
	for (i = 0; i < h; ++i)
	{
		bstTraverseAtLevel(root, i);
	}
	return NULL;
}

bst_t * bstTraverseLevelOrderQUEUE(bst_t *root)
{
	bst_dlist_t *head = NULL, *tail = NULL, *tmp = NULL;
	bst_t *curr = root;
	while (curr){
		printf("%d\t", curr->data);
		if(curr->left) {
			tmp = (bst_dlist_t *)malloc(sizeof(bst_dlist_t));
			tmp->data = curr->left;
			tmp->prev = tmp->next = NULL;
			if (head){
				head->prev = tmp;
				tmp->next = head;
				head = tmp;
			} else {
				head = tail = tmp;
			}
		}
		if(curr->right) {
			tmp = (bst_dlist_t *)malloc(sizeof(bst_dlist_t));
			tmp->data = curr->right;
			tmp->prev = tmp->next = NULL;
			if (head){
				head->prev = tmp;
				tmp->next = head;
				head = tmp;
			} else {
				head = tail = tmp;
			}
		}

		if(tail) {
			curr = tail->data;
			tmp = tail;
			tail = tail->prev;
			free(tmp);
			if(tail == NULL)
				head = NULL;
		} else {
			curr = NULL;
		}
	}
	return root;
}

bst_t * bstFirstNodeAtLevel(bst_t *root, int level, int *print)
{
	if (!root)
	{
		return root;
	}
	if(*print == 0)
		return NULL;

	if(level==1 && *print==1){
		printf("%d\n", root->data);
		*print = 0;
	} else {
		bstFirstNodeAtLevel(root->left, level-1, print);
		bstFirstNodeAtLevel(root->right, level-1, print);
	}
	return NULL;
}

bst_t * bstLeftView(bst_t *root)
{
	int i;
	static int print;
	int h = bstHeight(root);
	for (i = 0; i <= h; ++i)
	{
		print = 1;
		bstFirstNodeAtLevel(root, i, &print);
	}
	return NULL;
}


bst_t * bstLca(bst_t *root, int data1, int data2)
{
	if(bstSearch(root, data1) == NULL ||
		bstSearch(root, data2) == NULL) {
		return NULL;
	}
	while(root) {
		if (root->data > data1 && root->data > data2)
		{
			root = root->left;
		} else if (root->data < data1 && root->data < data2) {
			root = root->right;
		} else {
			return root;
		}
	}
	return NULL;
}

bst_t * bstLcaREC(bst_t *root, int data1, int data2)
{
	if(!root) {
		return NULL;
	}
	if (root->data > data1 && root->data > data2)
	{
		return bstLcaREC(root->left, data1, data2);
	}
	if (root->data < data1 && root->data < data2) {
		return bstLcaREC(root->right, data1, data2);
	} 
	return root;
}

bst_t * bstSearch(bst_t *root, int data)
{
	while(root){
		if(data == root->data) {
			return root;
		} else if (data < root->data) {
			root = root->left;
		} else {
			root = root->left;
		}
	}
	return NULL;
}
bst_t * bstSearchREC(bst_t *root, int data)
{
	bst_t * tmp = NULL;
	if (root){
		if (data == root->data) {
			return root;
		} else if (data < root->data) {
			tmp = bstSearchREC(root->left, data);
		} else {
			tmp = bstSearchREC(root->right, data);
		}
		return tmp;
	}
	return NULL;
}
bst_t * bstMaxElement(bst_t *root)
{
	bst_t * p = root;
	while(root){
		p = root;
		root = root->right;
	}
	return p;
}
bst_t * bstMaxElementREC(bst_t *root)
{
	bst_t *  tmp = NULL;
	if (root == NULL || root->right == NULL)
		return root;
	tmp = bstMaxElementREC(root->right);
	return tmp;
}
bst_t * bstMinElement(bst_t *root)
{
	bst_t * p = root;
	while(root){
		p = root;
		root = root->left;
	}
	return p;
}
bst_t * bstMinElementREC(bst_t *root)
{
	bst_t *  tmp = NULL;
	if (root == NULL || root->left == NULL)
		return root;
	tmp = bstMinElementREC(root->left);
	return tmp;
}
bst_t * bstCreateCopy(bst_t *root)
{
	bst_t *new = NULL;
	if(!root){
		return root;
	}
	else {
		new = (bst_t *)malloc(sizeof(bst_t));
		new->data = root->data;
		new->left = bstCreateCopy(root->left);
		new->right = bstCreateCopy(root->right);
	}
	return new;
}
int bstIsCopy(bst_t *root1, bst_t *root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;
	return ((root1 == root2) && (root1->data == root2->data) && 
		(bstIsCopy(root1->left, root2->left)) && (bstIsCopy(root1->right, root2->right)));
}
bst_t * bstCreateMirror(bst_t *root)
{
	bst_t *new = NULL;
	if(!root){
		return root;
	}
	else {
		new = (bst_t *)malloc(sizeof(bst_t));
		new->data = root->data;
		new->left = bstCreateCopy(root->right);
		new->right = bstCreateCopy(root->left);
	}
	return new;
}
int bstIsMorror(bst_t *root1, bst_t *root2)
{
	if(root1 == NULL && root2 == NULL)
		return 1;
	if(root1 == NULL || root2 == NULL)
		return 0;
	return ((root1->data == root2->data) &&
		(bstIsMorror(root1->left, root2->right)) &&
		(bstIsMorror(root1->right, root2->left)));
}
int bstIsBST_1(bst_t *root)
{
	
}
int bstIsBST_2(bst_t *root)
{
	
}
int bstHeight(bst_t *root)
{
	int lh = 0, rh = 0;
	bst_t *p = NULL;
	if (!root)
	{
		return 0;
	}
	p = root;
	while(p){
		if (p->left)
		{
			p = p->left;
		} else {
			p = p->right;
		}
		lh++;
	}
	p = root;
	while(p){
		if (p->right)
		{
			p = p->right;
		} else {
			p = p->left;
		}
		rh++;
	}
	if (lh > rh)
	{
		return lh;
	}
	return rh;
}

int bstHeightREC(bst_t *root)
{
	int lh = 0, rh = 0;
	if (!root)
	{
		return 1;
	}
	lh += bstHeight(root->left);
	rh += bstHeight(root->right);
	if (lh > rh)
	{
		return lh+1;
	}
	return rh+1;
}

int bstIsBalabced(bst_t *root)
{
	int lh = 0, rh = 0;
	if (!root)
	{
		return 1;
	}
	lh = bstHeight(root->left);
	rh = bstHeight(root->right);
	if (abs(lh-rh) > 1)
	{
		printf("root at %d  -- the imbalance  lh=%d , rh=%d\n", root->data, lh, rh);
		return 0;
	}
	return bstIsBalabced(root->left) && bstIsBalabced(root->right);
}
int bstIsBalabcedREC(bst_t *root, int *height)
{
	int lh = 0, rh = 0;
	if (!root)
	{
		return 1;
	}
	printf("root at %d  --  lh=%d , rh=%d\n", root->data, lh, rh);
	lh += bstIsBalabcedREC(root->left, height);
	rh += bstIsBalabcedREC(root->right, height);
	if (abs(lh-rh) > 1)
	{
		printf("root at %d  -- the imbalance  lh=%d , rh=%d\n", root->data, lh, rh);
		*height = 1;
	}
	if(lh > rh)
		return lh+1;
	else
		return rh+1;
}

int bstCountLeaf(bst_t  *root)
{
	int count = 0;
	if (!root)
	{
		return 0;
	}
	count += bstCountLeaf(root->left);
	count += bstCountLeaf(root->right);
	if (root->left == NULL && root->right == NULL){
		printf("Leaf at %d  %d\n", root->data, count);
		return count +1;
	}
	return count;
}