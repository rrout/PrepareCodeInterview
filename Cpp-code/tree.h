#include "sheader.h"
#ifndef __TREE_H__
#define __TREE_H__
template <class T>
class treenode
{
public:
	T data;
	treenode *left;
	treenode *right;

	treenode(T dat){
		data = dat;
		left = right = nullptr;
	}
	void print() {
		std::cout << "Left= " << left << " | data= " <<
			data << " | right= " << right << std::endl;
	}
};


template <class T>
class tree
{
private:
	treenode<T> *treeroot;
	bool bst;
	int depth;
	int nodes;
	int leafs;
	treenode<T> *insertREC(treenode<T> *root, T data);
	treenode<T> *removeREC(treenode<T> *root, T data);
	treenode<T> *removeREC(treenode<T> *root);
	void print(treenode<T> *root, int n);
	void preorderTraverseREC(treenode<T> *root);
	void inorderTraverseREC(treenode<T> *root);
	void postorderTraverseREC(treenode<T> *root);
	void levelorderTraverseREC(treenode<T> *root, int h);
	void printLeftViewREC(treenode<T> *root, int h, bool *print);

	treenode<T> *searchREC(treenode<T> *root, T data);
	treenode<T> *minElemREC(treenode<T> *root);
	treenode<T> *maxElemREC(treenode<T> *root);
	treenode<T> *findLcaREC(treenode<T> *root);
	treenode<T> *findbstLcaREC(treenode<T> *root);
	treenode<T> *findDeepImbalanceNodeREC(treenode<T> *root);
	int heightREC(treenode<T> *root);
	bool isBstREC(treenode<T> *root);
	bool isBalancedREC(treenode<T> *root);

public:
	tree();
	~tree();
	void insert(T data);
	void insertREC(T data);
	void remove(T data);
	void removeREC(T data);
	void remove();
	void removeREC();
	void print();
	void preorderTraverse();
	void preorderTraverseREC();
	void inorderTraverse();
	void inorderTraverseREC();
	void postorderTraverse();
	void postorderTraverseREC();
	void levelorderTraverse();
	void levelorderTraverseREC();
	void printLeftView();
	void printLeftViewREC();

	treenode<T> *search(T data);
	treenode<T> *searchREC(T data);
	treenode<T> *minElem();
	treenode<T> *minElemREC();
	treenode<T> *maxElem();
	treenode<T> *maxElemREC();
	treenode<T> *findLca();
	treenode<T> *findLcaREC();
	treenode<T> *findBstLca();
	treenode<T> *findbstLcaREC();
	treenode<T> *findDeepImbalanceNodeREC();
	

	int height();
	int heightREC();

	bool isBst();
	bool isBstREC();
	bool isBalanced();
	bool isBalancedREC();

};

#endif //__TREE_H__