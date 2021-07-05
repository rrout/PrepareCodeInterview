#include "header.h"
tree_t *treeInsert(tree_t *root, int data) {
	tree_t *p = root, *prev = NULL;
	tree_t *node = (tree_t *)malloc(sizeof(tree_t));
	node->data = data;
	node->left = node->right = NULL;
	if (!root) {
		return node;
	}
	while(p) {
		prev = p;
		if (data < p->data) {
			p = p->left;
		} else {
			p = p->right;
		}
	}
	if (data < prev->data)
		prev->left = node;
	else
		prev->right = node;
	return root;
}
tree_t *treeInsertREC(tree_t *root, int data) {
	if (!root) {
		root = (tree_t *)malloc(sizeof(tree_t));
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	if (data < root->data) {
		root->left = treeInsertREC(root->left, data);
	} else {
		root->right = treeInsertREC(root->right, data);
	}
	return root;
}
tree_t *treeRemove(tree_t *root, int data) {}
tree_t *treeRemoveREC(tree_t *root, int data) {}
tree_t *treeDelete(tree_t *root) {
	std::stack<tree_t *> s1;
	std::stack<tree_t *> s2;
	while(root || s1.empty() != true) {
		while(root) {
			s1.push(root);
			root = root->left;
		}
		root = s1.top();
		s2.push(root);
		s1.pop();
		root = root->right;
	}
	std::cout << "deleting ";
	while(s2.empty() != true) {
		root = s2.top();
		s2.pop();
		std::cout << root->data << " ";
		free(root);
	}
	std::cout << std::endl;
	return NULL;
}
tree_t *treeDeleteREC(tree_t *root) {
	if (!root) {
		return root;
	}
	treeDeleteREC(root->left);
	treeDeleteREC(root->right);
	free(root);
	return NULL;
}
tree_t *treeBstMinElem(tree_t *root) {
	while(root && root->left) {
		root = root->left;
	}
	return root;
}
tree_t *treeBstMinElemREC(tree_t *root) {
	tree_t *tmp = NULL;
	if (root == NULL || root->left == NULL) {
		return root;
	}
	tmp = treeBstMinElemREC(root->left);
	return tmp;
}
tree_t *treeBstMaxElem(tree_t *root) {
	while(root && root->right) {
		root = root->right;
	}
	return root;
}
tree_t *treeBstMaxElemREC(tree_t *root) {
	tree_t *tmp = NULL;
	if (root == NULL || root->right == NULL) {
		return root;
	}
	tmp = treeBstMaxElemREC(root->right);
	return tmp;
}
tree_t *treeSearch(tree_t *root, int data) {}
tree_t *treeSearchREC(tree_t *root, int data) {}
tree_t *treeBstSearch(tree_t *root, int data) {
	if (!root) {
		return root;
	}
	while(root) {
		if (data < root->data)
			root = root->left;
		else if (data > root->data)
			root = root->right;
		else
			return root;
	}
	return NULL;
}
tree_t *treeBstSearchREC(tree_t *root, int data) {
	tree_t *tmp = NULL;
	if (!root) {
		return root;
	}
	if (data < root->data) {
		tmp = treeBstSearchREC(root->left, data);
	} else if (data > root->data) {
		tmp = treeBstSearchREC(root->right, data);
	} else {
		return root;
	}
	return tmp;
}
tree_t *treeLca(tree_t *root, int data1, int data2) {
	tree_t *lLca = NULL;
	tree_t *rLca = NULL;
	if (!root) {
		return root;
	}
	if (root->data == data1 || root->data == data2)
		return root;
	lLca = treeLca(root->left, data1, data2);
	rLca = treeLca(root->right, data1, data2);
	if(lLca && rLca)
		return root;
	if (lLca)
		return lLca;
	if (rLca)
		return rLca;

}
tree_t *treeBstLca(tree_t *root, int data1, int data2) {
	if (!root) {
		return root;
	}
	while (root) {
		if (root->data > data1 && root->data > data2) {
			root = root->left;
		}
		else if (root->data < data1 && root->data < data2) {
			std::cout << root->data << std::endl;
			root = root->right;
		}
		else {
			return root;
		}
	}
	return root;
}
tree_t *treeBstLcaREC(tree_t *root, int data1, int data2) {
	tree_t *tmp = NULL;
	if (!root) {
		return root;
	}
	if (root->data > data1 && root->data > data2)
		tmp = treeBstLcaREC(root->left, data1, data2);
	else if (root->data < data1 && root->data < data2)
		tmp = treeBstLcaREC(root->right, data1, data2);
	else
		return root;
	return tmp;
}
tree_t *treeCopy(tree_t *root) {
	if (!root) {
		return root;
	}
	tree_t *node = (tree_t *)malloc(sizeof(tree_t));
	node->data = root->data;
	node->left = node->right = NULL;
	node->left = treeCopy(root->left);
	node->right = treeCopy(root->right);
	return node;
}
tree_t *treeMirrorCopy(tree_t *root) {
	if (!root) {
		return root;
	}
	tree_t *node = (tree_t *)malloc(sizeof(tree_t));
	node->data = root->data;
	node->left = node->right = NULL;
	node->left = treeMirrorCopy(root->right);
	node->right = treeMirrorCopy(root->left);
	return node;
}
tree_t *treeConvertCopy(tree_t *root) {}
tree_t *treeConvertMirrorCopy(tree_t *root) {}
tree_t *treeInorderSuccessor(tree_t *root) {}
tree_t *treeInorderSuccessorREC(tree_t *root) {}
tree_t *treeInorderPredissor(tree_t *root) {}
tree_t *treeInorderPredissorREC(tree_t *root) {}
tree_t *treeCreateFromArray(int *arr, int size) {}
tree_t *treeBstCreateFromArray(int *arr, int size) {}
tree_t *treeGetDeepImbalanceNode(tree_t *root) {}
tree_t *treeGetDeepImbalanceNodeREC(tree_t *root) {}

int treeHeight(tree_t *root) {
	tree_t *p = NULL;
	int lh = 0;
	int rh = 0;
	if (!root) {
		return 0;
	}
	p = root;
	while (p) {
		lh++;
		if (p->left)
			p = p->left;
		else
			p = p->right;
	}
	p = root;
	while (p) {
		rh++;
		if (p->right)
			p = p->right;
		else
			p = p->left;
	}
	if(lh > rh)
		return lh;
	else
		return rh;
}
int treeHeightREC(tree_t *root) {
	int lh = 0;
	int rh = 0;
	if (!root) {
		return 0;
	}
	lh += treeHeightREC(root->left);
	rh += treeHeightREC(root->right);
	if(lh > rh)
		return lh+1;
	else
		return rh+1;
}
int treeNodeCount(tree_t *root) {
	if (!root) {
		return 0;
	}
	std::stack<tree_t *> s;
	int count = 0;
	s.push(root);
	while(s.empty() != true) {
		root = s.top();
		s.pop();
		count++;
		if (root->left)
			s.push(root->left);
		if (root->right)
			s.push(root->right);
	}
	return count;
}
int treeNodeCountREC(tree_t *root) {
	if (!root) {
		return 0;
	}
	int count = 0;
	count += treeNodeCountREC(root->left);
	count += treeNodeCountREC(root->right);
	return count + 1;
}
int treeLeafCount(tree_t *root) {
	if (!root) {
		return 0;
	}
	std::stack<tree_t *> s;
	int count = 0;
	s.push(root);
	while(s.empty() != true) {
		root = s.top();
		s.pop();
		if (root->left == NULL && root->right == NULL) {
			count++;
		}
		if (root->left)
			s.push(root->left);
		if (root->right)
			s.push(root->right);
	}
	return count;	
}
int treeLeafCountREC(tree_t *root) {
	if (!root) {
		return 0;
	}
	int count = 0;
	count += treeLeafCountREC(root->left);
	count += treeLeafCountREC(root->right);
	if(root->left == NULL && root->right == NULL) {
		return count + 1;
	}
	return count;	
}

void treePrintPreOrder(tree_t *root) {
	std::cout << "Pre Order  : ";
	if (!root) {
		return;
	}
	std::stack<tree_t *> s;
	s.push(root);
	while (s.empty() != true) {
		root = s.top();
		s.pop();
		std::cout << root->data << " ";
		if (root->right)
			s.push(root->right);
		if (root->left)
			s.push(root->left);
	}
	std::cout << std::endl;
}
void treePrintPreOrderREC(tree_t *root) {
	if (!root) {
		return;
	}
	std::cout << root->data << " ";
	treePrintPreOrderREC(root->left);
	treePrintPreOrderREC(root->right);
}
void treePrintInOrder(tree_t *root) {
	std::cout << "In Order   : ";
	if (!root) {
		return;
	}
	std::stack<tree_t *> s;
	while (root || s.empty() != true) {
		while(root) {
			s.push(root);
			root = root->left;
		}
		root = s.top();
		std::cout << root->data << " ";
		s.pop();
		root = root->right;
	}
	std::cout << std::endl;
}
void treePrintInOrderREC(tree_t *root) {
	if (!root) {
		return;
	}
	treePrintInOrderREC(root->left);
	std::cout << root->data << " ";
	treePrintInOrderREC(root->right);
}
void treePrintPostOrder(tree_t *root) {
	std::cout << "Post Order : ";
	if (!root) {
		return;
	}
	std::stack<tree_t *> s1;
	std::stack<tree_t *> s2;
	s1.push(root);
	while (s1.empty() != true) {
		root = s1.top();
		s1.pop();
		s2.push(root);
		if (root->left)
			s1.push(root->left);
		if (root->right)
			s1.push(root->right);
	}
	while(s2.empty() != true) {
		root = s2.top();
		s2.pop();
		std::cout << root->data << " ";
	}
	std::cout << std::endl;
}
void treePrintPostOrderREC(tree_t *root) {
	if (!root) {
		return;
	}
	treePrintPostOrderREC(root->left);
	treePrintPostOrderREC(root->right);
	std::cout << root->data << " ";
}
void treePrintInOrderGRAPH(tree_t *root, int n) {
	if (!root) {
		return;
	}
	treePrintInOrderGRAPH(root->right, n+1);
	for (int i = 0; i < n; ++i)
	{
		std::cout << "\t";
	}
	std::cout << root->data << std::endl;
	treePrintInOrderGRAPH(root->left, n+1);
}
void treePrintLevelOrder(tree_t *root) {
	std::queue<tree_t *> q;
	std::cout << "Level Order: ";
	if (!root) {
		return;
	}
	q.push(root);
	while(q.empty() != true) {
		root = q.front();
		std::cout << root->data << " ";
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
		q.pop();
	}
	std::cout << std::endl;
}
void treePrintAtLevel(tree_t *root, int level) {
	if (!root) {
		return;
	}
	treePrintAtLevel(root->left, level-1);
	if (level == 0)
		std::cout << root->data << " ";
	treePrintAtLevel(root->right, level-1);
}
void treePrintLevelOrderREC(tree_t *root) {
	if (!root) {
		return;
	}
	int height = treeHeight(root);
	for (int i = 0; i < height; ++i)
	{
		treePrintAtLevel(root, i);
	}
	std::cout << std::endl;
}
void treePrintLeftView(tree_t *root) {
	std::cout << "Left View: ";
	if (!root) {
		return;
	}
	std::queue<tree_t *> q;
	q.push(root);
	while(q.empty() != true) {
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			root = q.front();
			if(i == 0)
				std::cout << root->data << " ";
			q.pop();
			if (root->left)
				q.push(root->left);
			if (root->right)
				q.push(root->right);
		}
	}
	std::cout << std::endl;
}
void treePrintLeftViewREC(tree_t *root, int level, bool *print) {
	if (!root) {
		return;
	}
	treePrintLeftViewREC(root->left, level-1, print);
	if (*print == false && level == 0) {
		std::cout << root->data << " ";
		*print = true;
	}
	treePrintLeftViewREC(root->right, level-1, print);
}
void treePrintLeftViewREC(tree_t *root) {
	std::cout << "Left View: ";
	if (!root) {
		return;
	}
	int height = treeHeight(root);
	for (int i = 0; i < height; ++i)
	{
		bool print = false;
		treePrintLeftViewREC(root, i, &print);
	}
	std::cout << std::endl;
}
void treePrintRightView(tree_t *root) {
	std::cout << "Right View: ";
	if (!root) {
		return;
	}
	std::queue<tree_t *> q;
	q.push(root);
	while(q.empty() != true) {
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			root = q.front();
			if(i == 0)
				std::cout << root->data << " ";
			q.pop();
			if (root->right)
				q.push(root->right);
			if (root->left)
				q.push(root->left);
		}
	}
	std::cout << std::endl;
}
void treePrintRightViewREC(tree_t *root, int level, bool *print) {
	if (!root) {
		return;
	}
	treePrintRightViewREC(root->right, level-1, print);
	if (*print == false && level == 0) {
		std::cout << root->data << " ";
		*print = true;
	}
	treePrintRightViewREC(root->left, level-1, print);
}
void treePrintRightViewREC(tree_t *root) {
	std::cout << "Right View: ";
	if (!root) {
		return;
	}
	int height = treeHeight(root);
	for (int i = 0; i < height; ++i)
	{
		bool print = false;
		treePrintRightViewREC(root, i, &print);
	}
	std::cout << std::endl;
}

bool treeIsBst(tree_t *root) {
	tree_t *prev = NULL;
	if (!root) {
		return true;
	}
	std::stack<tree_t *> s;
	while(root || s.empty() != true) {
		while(root) {
			s.push(root);
			root = root->left;
		}

		root = s.top();
		if (prev && prev->data > root->data)
			return false;
		prev = root;
		s.pop();
		root = root->right;
	}
	return true;
}
bool treeIsBstREC(tree_t *root, tree_t *prev) {
	bool ret = true;
	if (!root) {
		return true;
	}
	ret &= treeIsBstREC(root->left, prev);
	if (prev && prev->data > root->data) {
		//std::cout << root->data << std::endl;
		return false;
	}
	prev = root;
	ret &= treeIsBstREC(root->right, prev);
	return ret;
}
bool treeIsBstREC(tree_t *root) {
	tree_t *prev = NULL;
	if (!root) {
		return true;
	}
	return treeIsBstREC(root, prev);
}
int treeIsHeightBalanced(tree_t *root, bool *balanced) {
	int lh = 0, rh = 0;
	if (!root) {
		return 0;
	}
	lh = treeIsHeightBalanced(root->left, balanced);
	rh = treeIsHeightBalanced(root->right, balanced);
	if (abs(lh-rh) > 1) {
		*balanced = false;
	}
	if (lh > rh)
		return lh + 1;
	else
		return rh + 1;
}
bool treeIsHeightBalanced(tree_t *root) {
	bool balanced = false;
	treeIsHeightBalanced(root, &balanced);
	return balanced;
}
bool treeIsHeightBalancedREC(tree_t *root) {
	int lh = 0;
	int rh = 0;
	if (!root) {
		return 0;
	}
	lh = treeHeight(root->left);
	rh = treeHeight(root->right);
	if(abs(lh-rh) > 1) {
		return false;
	}
	return (treeIsHeightBalancedREC(root->left) &
			treeIsHeightBalancedREC(root->right));
}
bool treeIsCopy(tree_t *root) {}
bool treeIsMirror(tree_t *root) {}