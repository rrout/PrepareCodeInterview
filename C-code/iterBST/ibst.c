#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
#include "ibst.h"

ibst_t *ibstInsert(ibst_t *root, int data)
{
	ibst_t *par = NULL, *curr = NULL, *tmp = NULL;
	tmp = (ibst_t *) malloc (sizeof(ibst_t));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	if (root == NULL)
	{
		return tmp;
	} else {
		curr = root;
		while(curr){
			par = curr;
			if(data < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if(data < par->data)
			par->left = tmp;
		else
			par->right = tmp;
	}
	return root;
}

ibst_t *ibstTravreseIn(ibst_t *root)
{
	std::stack<ibst_t *> s;
	std::cout << "ibstTravreseIn" << std::endl;
	while(root || s.empty()==false){
		while(root){
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		std::cout << " " << root->data;

		root = root->right;
	}
	std::cout << std::endl;
	return root;
}
ibst_t *ibstDelete(ibst_t *root, int data)
{
	ibst_t *par = NULL, *curr = NULL , *psucc = NULL, *succ = NULL;
	if (ibstSearch(root, data) == NULL)
	{
		return root;
	} else {
		curr = par = root;
		while(curr){
			if (data < curr->data)
			{
				par = curr;
				curr = curr->left;
			} else if (data > curr->data){
				par = curr;
				curr = curr->right;
			} else {
				if(curr->left == NULL && curr->right == NULL){ 		/* Both chields are NULL */
					if(par->left == curr)
						par->left = NULL;
					else
						par->right = NULL;
					free(curr);
					break;
				} else if (curr->left && curr->right) { 			/* Both chields are Valid*/
					psucc = curr;
					succ = curr->right;
					while(succ->left){
						psucc = succ;
						succ = succ->left;
					}
					if (psucc != root)
					{
						psucc->left = succ->right;
					} else {
						psucc->right = succ->right;
					}
					curr->data = succ->data;
					free(succ);
					break;
				} else {											/* one chield is NULL */
					if(curr->left == NULL) {
						if(par->left == curr)
							par->left = curr->right;
						else
							par->right = curr->right;
					} else {
						if(par->left == curr)
							par->left = curr->left;
						else
							par->right = curr->left;
					}
					free(succ);
					break;
				}
			}
		}
	}
	return root;
}
ibst_t *ibstSearch(ibst_t *root, int data)
{
	ibst_t *par = NULL, *curr = NULL;
	curr = root;
	while(curr){
		if (data < curr->data)
		{
			curr = curr->left;
		} else if (data > curr->data){
			curr = curr->right;
		} else {
			return curr;
		}
	}
	return NULL;
}



ibst_t *ibstFromArray(ibst_t *root, int *arr, int start, int end)
{
	int mid = 0;

	if(start > end)
		return root;

	mid = (start+end)/2;
	std::cout << "insert " << arr[mid] << std::endl;
	root = ibstInsert(root, arr[mid]);
	ibstFromArray(root, arr, start, mid-1);
	ibstFromArray(root, arr, mid+1, end);
	return root;
}
ibst_t *ibstFromArray(ibst_t *root, int *arr, int arrSize)
{
	sort(arr, arr+arrSize);
	return ibstFromArray(root, arr, 0, arrSize-1);
}
bool ibstIsBST(ibst_t *root)
{
	int prev = 0;
	std::stack<ibst_t *> s;
	while(root || s.empty()==false){
		while(root){
			s.push(root);
			root = root->left;
		}
		
		root = s.top();
		if(prev >root->data)
			return false;

		prev = root->data;
		s.pop();

		root = root->right;
	}
	return true;
}
ibst_t * ibstIinorderPredecessor(ibst_t *root, int data)
{
	ibst_t * prev = NULL;
	std::stack<ibst_t *> s;
	while(root || s.empty()==false){
		while(root){
			s.push(root);
			root = root->left;
		}
		
		root = s.top();
		if(data == root->data)
			return prev;

		prev = root;
		s.pop();

		root = root->right;
	}
	return NULL;
}
ibst_t *ibstIinorderPredecessor1(ibst_t *root, int data)
{
	ibst_t *par = NULL, *curr = NULL;
	curr = root;
	while(curr){
		if (data < curr->data)
		{
			curr = curr->left;
		} else if (data > curr->data){
			par = curr;
			curr = curr->right;
		} else {
			if(curr->left){
				curr = curr->left;
				while(curr->right)
					curr = curr->right; /*find Max in right sub tree*/
				return curr;
			}
			return par;
		}
	}
	return NULL;
}
ibst_t *ibstIinorderSuccessor(ibst_t *root, int data)
{
	ibst_t *par = NULL, *curr = NULL;
	curr = root;
	while(curr){
		if (data < curr->data)
		{
			par = curr;
			curr = curr->left;
		} else if (data > curr->data){
			curr = curr->right;
		} else {
			if(curr->right){
				curr = curr->right;
				while(curr->left)
					curr = curr->left; /*find Max in right sub tree*/
				return curr;
			}
			return par;
		}
	}
	return NULL;
}
ibst_t *ibstLCA(ibst_t *root, int data1, int data2)
{
	if(root == NULL)
		return root;
	while(root){
		if(data1 < root->data  && data2 < root->data)
			root = root->left;
		else if(data1 > root->data  && data2 > root->data)
			root = root->right;
		else
			return root;
	}
	return NULL;
}
ibst_t *ibstLCAnonBST(ibst_t *root, int data1, int data2)
{
	ibst_t *left = NULL, *right = NULL;
	if(root == NULL)
		return root;
	if (root->data == data1 || root->data == data2)
	{
		return root;
	}
	left = ibstLCAnonBST(root->left, data1, data2);
	right = ibstLCAnonBST(root->right, data1, data2);

	if (left && right)
	{
		return root;
	} else if (left) {
		return left;
	} else {
		return right;
	}
}
ibst_t *ibstNthElementAscending(ibst_t *root, int n, int *count)
{
	ibst_t * tmp = NULL;
	if(!root)
		return root;
	std::cout << "ibstNthElementAscending " << n << "/"<< *count << std::endl;
	tmp = ibstNthElementAscending(root->left, n, count);
	
	if(tmp != NULL)
		return tmp;
	
	if(*count == n){
		std::cout << "ibstNth: " << root->data << "/" << *count<< std::endl;
		return root;
	}
	*count = *count+1;
	std::cout << "ibstNthElementAscending : " << root->data << "//" << *count<< std::endl;
	
	tmp = ibstNthElementAscending(root->right, n, count);
	return tmp;
}
ibst_t *ibstNthElementDescending(ibst_t *root, int n, int *count)
{
	ibst_t * tmp = NULL;
	if(!root)
		return root;

	tmp = ibstNthElementDescending(root->right, n, count);
	
	if(tmp != NULL)
		return tmp;
	
	if(*count == n){
		return root;
	}
	*count = *count+1;

	tmp = ibstNthElementDescending(root->left, n, count);
	return tmp;
}
ibst_t *ibstMin(ibst_t *root)
{
	if(!root)
		return root;
	while(root->left){
			root = root->left;
	}
	return root;
}
ibst_t *ibstMax(ibst_t *root)
{
	if(!root)
		return root;
	while(root->right){
			root = root->right;
	}
	return root;

}