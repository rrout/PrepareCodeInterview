#include "globalheader.h"

tree_t *treeInsert(tree_t *root, int data)
{
	tree_t *par = NULL, *curr = NULL;
	tree_t *node = (tree_t *)malloc(sizeof(tree_t));
	node->data = data;
	node->left = node->right = NULL;
	if(!root) {
		return node;
	}
	curr = root;
	while(curr) {
		par = curr;
		if (data < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if(data < par->data)
		par->left = node;
	else
		par->right = node;
	return root;
}
tree_t *treeInsertREC(tree_t *root, int data)
{
	tree_t *p = NULL;
	if (!root)
	{
		root = (tree_t *)malloc(sizeof(tree_t));
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	if (data < root->data)
	{
		root->left = treeInsertREC(root->left, data);
	} else {
		root->right = treeInsertREC(root->right, data);
	}
	return root;
}
tree_t *treeDelete(tree_t *root, int data)
{
	tree_t *tmp = NULL, *curr = NULL,*par = NULL, *s = NULL,*sp = NULL;
	if (!root)
	{
		return root;
	}
	curr = root;
	while(curr) {
		if (data  < root->data)
		{
			par = curr;
			curr = curr->left;
		} else if (data  > root->data)
		{
			par = curr;
			curr = curr->right;
		} else {
			break;
		}
	}
	if (!curr)
	{
		return root;
	}
	if (curr->left == NULL || curr->right == NULL)
	{
		if (curr->left == NULL)
		{
			tmp = curr->right;
		} else {
			tmp = curr->right;
		}
		if (!par)
			return tmp;
		else {
			if (par->left == curr)
				par->left = tmp;
			else
				par->right = tmp;
			free(curr);
			return root;
		}
	} else {
		sp = curr;
		s = curr->right;
		while(s->left) {
			sp = s;
			s = s->left;
		}
		curr->data = s->data;
		if (sp->right == s)
			sp->right = s->right;
		else
			sp->left = s->right;
	}
	return root;
}
tree_t *treeDeleteREC(tree_t *root, int data)
{
	tree_t * tmp = NULL;
	if (!root)
	{
		return root;
	}
	if (data < root->data)
	{
		root->left = treeDeleteREC(root->left, data);
	} else if (data > root->data) {
		root->right = treeDeleteREC(root->right, data);
	} else {
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}else if(root->left == NULL){
			tmp = root->right;
			free(root);
			return tmp;
		}else if(root->right == NULL){
			tmp = root->left;
			free(root);
			return tmp;
		}else{
			tmp = root->right;
			while(tmp->left)
				tmp = tmp->left;
			root->data = tmp->data;
			root->right = treeDeleteREC(root->right, tmp->data);
			return root;
		}
	}
	return root;
}
tree_t *treeDeleteREC2(tree_t *root, int data)
{
	tree_t * tmp = NULL;
	if (!root)
	{
		return root;
	}
	if (root->data == data)
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}else if(root->left == NULL){
			tmp = root->right;
			free(root);
			return tmp;
		}else if(root->right == NULL){
			tmp = root->left;
			free(root);
			return tmp;
		}else{
			tmp = root->right;
			while(tmp->left)
				tmp = tmp->left;
			root->data = tmp->data;
			root->right = treeDeleteREC(root->right, tmp->data);
			return root;
		}
	}
	root->left = treeDeleteREC(root->left, data);
	root->right = treeDeleteREC(root->right, data);
	return root;
}
tree_t *treeDelete(tree_t *root)
{
	std::stack<tree_t *> s;
	std::vector<tree_t *> v;
	tree_t * search = root;
	while(search || s.empty() == false) {
		while(search) {
			s.push(search);
			search = search->left;
		}
		search = s.top();
		v.push_back(search);
		s.pop();
		search = search->right;
	}
	std::vector<tree_t *>::iterator i ;
	for (i = v.begin(); i != v.end(); ++i)
	{
		//std::cout << (*i)->data << std::endl;
		free(*i);
	}
	return NULL;
}
tree_t *treeDeleteREC(tree_t *root)
{
	if (!root)
	{
		return root;
	}
	treeDelete(root->left);
	treeDelete(root->right);
	free(root);

	return NULL;
}
tree_t *treeSearch(tree_t *root, int data)
{
	if (!root)
	{
		return root;
	}
}
tree_t *treeSearchREC(tree_t *root, int data)
{
	tree_t * search = NULL;
	if (!root)
	{
		return root;
	}
	search = treeSearchREC(root->left, data);
	if (data == root->data)
	{
		return root;
	}
	search = treeSearchREC(root->right, data);
	return search;
}
tree_t *treeBinarySearch(tree_t *root, int data)
{
	if (!root)
	{
		return root;
	}
	while(root) {
		if (data < root->data)
		{
			root = root->left;
		} else if (data < root->data){
			root = root->right;
		} else {
			return root;
		}
	}
	return NULL;
}
tree_t *treeBinarySearchREC(tree_t *root, int data)
{
	tree_t * search = NULL;
	if (!root)
	{
		return root;
	}
	if (data ==root->data) {
		return root;
	} else if (data < root->data) {
		search = treeBinarySearchREC(root->left, data);
	} else {
		search = treeBinarySearchREC(root->right, data);
	}
	return search;
}
tree_t *treeMaxElement(tree_t *root)
{
	while(root && root->right){
		root = root->right;
	}
	return root;
}
tree_t *treeMaxElementREC(tree_t *root)
{
	tree_t * max = NULL;
	if (root && root->right == NULL)
	{
		return root;
	}
	max = treeMaxElementREC(root->right);
	return max;
}
tree_t *treeMinElement(tree_t *root)
{
	while(root && root->left){
		root = root->left;
	}
	return root;
}
tree_t *treeMinElementREC(tree_t *root)
{
	tree_t * min = NULL;
	if (root && root->left == NULL)
	{
		return root;
	}
	min = treeMinElementREC(root->left);
	return min;
}
tree_t *treeFindLca(tree_t *root, int data1, int data2)
{
	
}
tree_t *treeFindLcaREC(tree_t *root, int data1, int data2)
{
	tree_t * llca = NULL, *rlca = NULL;
	if (!root)
	{
		return root;
	}

	if (root->data == data1 || root->data == data2)
	{
		return root;
	}
	llca = treeFindLcaREC(root->left, data1, data2);
	rlca = treeFindLcaREC(root->right, data1, data2);
	if (llca && rlca)
	{
		return root;
	}
	if (llca)
		return llca;
	else
		return rlca;
}
tree_t *treeBstFindLca(tree_t *root, int data1, int data2)
{
	if (!root)
	{
		return root;
	}
	while(root) {
		if (data1 < root->data && data2 < root->data)
		{
			root = root->left;
		} else if(data1 < root->data && data2 < root->data) {
			root = root->right;
		} else {
			return root;
		}
	}
	return NULL;
}
tree_t *treeBstFindLcaREC(tree_t *root, int data1, int data2)
{
	tree_t * lca = NULL;
	if (!root)
	{
		return root;
	}
	if (data1 < root->data && data2 < root->data) {
		lca = treeFindLcaREC(root->left, data1, data2);
	} else if (data1 < root->data && data2 < root->data) {
		lca = treeFindLcaREC(root->right, data1, data2);
	} else {
		return root;
	}
	return lca;
}
tree_t *treeBstInorderSuccessor(tree_t *root){}
tree_t *treeBstInorderSuccessorREC(tree_t *root){}
tree_t *treeBstInorderPredissor(tree_t *root){}
tree_t *treeBstInorderPredissorREC(tree_t *root){}
tree_t *treeMirrorCreate(tree_t *root){}
tree_t *treeMirrorCreateREC(tree_t *root)
{
	tree_t *mtree = NULL;
	if (!root)
	{
		return root;
	}
	if (root)
	{
		mtree = (tree_t *)malloc(sizeof(tree_t));
		mtree->data = root->data;
		mtree->left = treeMirrorCreateREC(root->right);
		mtree->right = treeMirrorCreateREC(root->left);
	}
	return mtree;
}
tree_t *treeCopyCreate(tree_t *root){}
tree_t *treeCopyCreateREC(tree_t *root)
{
	tree_t *ctree = NULL;
	if (root)
	{
		ctree = (tree_t *)malloc(sizeof(tree_t));
		ctree->data = root->data;
		ctree->left = treeCopyCreateREC(root->left);
		ctree->right = treeCopyCreateREC(root->right);
	}
	return ctree;
}
tree_t *treeCreateFromArray(int *arr, int size){}
tree_t *treeCreateFromArrayREC(int *arr, int size){}
tree_t *treeBstCreateFromArray(int *arr, int size)
{

}
//Helper
tree_t *treeBstCreateFromArrayREC(tree_t *root, int *arr, int start, int end)
{
	int mid = 0;
	if(start > end) {
		return NULL;
	}
	mid = (start+end)/2;
	std::cout << "insert " << arr[mid] << "--root at --" << ((root)?(root->data):0) << std::endl;
	root = treeInsert(root, arr[mid]);
	treeBstCreateFromArrayREC(root, arr, start, mid-1);
	treeBstCreateFromArrayREC(root, arr, mid+1, end);
	return root;
}
tree_t *treeBstCreateFromArrayREC(int *arr, int size)
{
	tree_t *root = NULL;
	std::sort(arr, arr+size);
	root = treeBstCreateFromArrayREC(root, arr, 0, size-1);
	return root;
}
tree_t *treeBstImbalanceNode(tree_t *root)
{
	tree_t *tmp = NULL;
	int lh = 0, rh = 0;
	if (!root)
	{
		return root;
	}

	tmp = treeBstImbalanceNode(root->left);
	tmp = treeBstImbalanceNode(root->right);

	lh = treeHeightREC(root->left);
	rh = treeHeightREC(root->right);
	if(tmp)
		return tmp;
	if(abs(lh - rh) > 1)
		return root;
	return tmp;
}
/*
https://webdocs.cs.ualberta.ca/~holte/T26/tree-rotation.html
The pivot node is the deepest node at which there is an imbalance. The rotator node is the root of the pivot's taller subtree.
There may be more nodes above the pivot's parent. 
Step 3 prunes the rotator's `inside' subtree, i.e. the one on the pivot's side.
Which of the rotator's subtrees is the inside subtree, which is the outside? 
It depends on whether the rotator is the left or right child of the pivot.
If the rotator is the right child (as in this picture), the inside subtree is its left subtree and the outside subtree is its right subtree.
On the other hand,
if the rotator is the left child the inside subtree is its right subtree and the outside subtree is its left subtree.
Step 4: Join the pruned inside subtree to the pivot (in the place where the rotator had been).
Step 5: Join the pivot to the rotator (in the place where inside had been).
Step 6: Join the rotator to the pivot's (original) parent (in the place where the pivot had been).

PIVOT = is the deepest node at which there is an imbalance;
rotator = is the pivot's taller subtree
inside = if(rotator is pivot's right child) ? (rotator's left subtree) : (rotator's right subtree) 
outside = vice versa

Step a: Join the inside to the pivot (in the place the rotator).
Step b: Join the pivot to the rotator (in the place ofinside).
Step c: Join the rotator to the pivot's (original) parent (in the place where the pivot had been).

if (inside is heavy), double Rotation needed
    if rotator is pivot's left  child, LR Rotation needed
        rotate at rotator( spivot = pivot->left , srotator = spivot->right;), then do main rotation
    if rotator is pivot's right child, RL Rotation needed
        rotate at rotator( spivot = pivot->right , srotator = spivot->left;), then do main rotation

*/
tree_t *treeBstBalance(tree_t *root)
{
	tree_t *ppivot = NULL, *pivot = NULL, *rotator = NULL, *inside = NULL, *curr = NULL, *spivot= NULL;
	int lh = 0, rh = 0;
	if (!root)
	{
		return root;
	}
	curr = root;

	pivot = treeBstImbalanceNode(root);
	if (pivot == NULL)
	{
		return root;
	}
	while(curr) {
		if (pivot->data < curr->data){
			ppivot = curr;
			curr = curr->left;
		} else if (pivot->data > curr->data) {
			ppivot = curr;
			curr = curr->right;
		} else {
			break;
		}
	}
	//std::cout << "pivot " << pivot->data << std::endl;
	lh = treeHeightREC(pivot->left);
	rh = treeHeightREC(pivot->right);
	if (lh > rh)
	{
		rotator = pivot->left;
		if(rotator && treeHeightREC(rotator->left) < treeHeightREC(rotator->right)) {
			spivot = pivot->left;
			rotator = spivot->right;
			inside = rotator->left;

			spivot->right = inside;
			rotator->left = spivot;
			pivot->left = rotator;
		}

		/* Right Rotation Logic */
		rotator = pivot->left;
		inside = rotator->right;

		pivot->left = inside;
		rotator->right = pivot;
		if(ppivot == NULL){
			return rotator;
		} else if (pivot == ppivot->left) {
			ppivot->left = rotator;
		} else if (pivot == ppivot->right) {
			ppivot->right = rotator;
		}
	} else {
		rotator = pivot->right;
		/* inside is left sub tree, if inside is more height thn outside, RL Rotation needed*/
		if(rotator && treeHeightREC(rotator->right) < treeHeightREC(rotator->left)) {
			spivot = pivot->right;
			rotator = spivot->left;
			inside = rotator->right;

			spivot->left = inside;
			rotator->right = spivot;
			pivot->right = rotator;
		}

		/* Left Rotation Logic */
		rotator = pivot->right;
		inside = rotator->left;

		pivot->right = inside;
		rotator->left = pivot;
		if(ppivot == NULL){
			return rotator;
		} else if (pivot == ppivot->left) {
			ppivot->left = rotator;
		} else {
			ppivot->right = rotator;
		}
	}
	return root;;
}

void treeTraversePreOrder(tree_t *root)
{
	std::stack<tree_t *> s;
	s.push(root);
	while(s.empty()==false) {
		root = s.top();
		s.pop();
		std::cout <<  " " << root->data;
		if (root->right)
			s.push(root->right);
		if (root->left)
			s.push(root->left);
	}
	std::cout << std::endl;
}
void treeTraversePreOrderREC(tree_t *root)
{
	if (!root)
	{
		return;
	}
	std::cout << " " << root->data;
	treeTraversePreOrderREC(root->left);
	treeTraversePreOrderREC(root->right);
}
void treeTraverseInOrder(tree_t *root)
{
	std::stack<tree_t *> s;
	while(root || s.empty()==false) {
		while(root){
			s.push(root);
			root = root->left;
		}
		root = s.top();
		std::cout <<  " " << root->data;
		s.pop();
		root = root->right;
	}
	std::cout << std::endl;
}
void treeTraverseInOrderREC(tree_t *root)
{
	if (!root)
	{
		return;
	}
	treeTraverseInOrderREC(root->left);
	std::cout << " " << root->data;
	treeTraverseInOrderREC(root->right);
}
void treeTraversePostOrder(tree_t *root)
{
	std::stack<tree_t *> s;
	std::stack<tree_t *> p;
	s.push(root);
	while(s.empty()==false) {
		root = s.top();
		s.pop();
		p.push(root);
		if (root->left)
			s.push(root->left);
		if (root->right)
			s.push(root->right);
	}
	while(p.empty()==false) {
		root = p.top();
		p.pop();
		std::cout <<  " " << root->data;
	}
	std::cout << std::endl;
}
void treeTraversePostOrderREC(tree_t *root)
{
	if (!root)
	{
		return;
	}
	treeTraversePostOrderREC(root->left);
	treeTraversePostOrderREC(root->right);
	std::cout << " " << root->data;
}
void treeTraverseLevelOrder(tree_t *root)
{
	tree_t *curr = root;
	std::queue<tree_t *> q;
	if (!root)
	{
		return;
	}
	q.push(root);
	while(curr){
		std::cout << " " << curr->data;
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
		q.pop();
		curr = q.front();
	}
	std::cout << std::endl;
}
//Helper
void treeTraverseLevelOrderREC(tree_t *root, int height)
{
	if (!root)
	{
		return;
	}
	if (height == 0)
	{
		std::cout << " " << root->data;
	}
	treeTraverseLevelOrderREC(root->left, height-1);
	treeTraverseLevelOrderREC(root->right, height-1);
}
void treeTraverseLevelOrderREC(tree_t *root)
{
	int height = treeHeight(root);
	for (int i = 0; i < height; ++i)
	{
		treeTraverseLevelOrderREC(root, i);
	}
	std::cout << std::endl;
}
void treeTraverseInOrderRECGRAPH(tree_t *root, int space)
{
	if (!root)
	{
		return;
	}
	treeTraverseInOrderRECGRAPH(root->right, space+1);
	for (int i = 0; i < space; ++i)
	{
		std::cout << "\t";
	}
	std::cout << " " << root->data << std::endl;
	treeTraverseInOrderRECGRAPH(root->left,space+1);
}


bool treeIsBst(tree_t *root)
{
	tree_t *prev = NULL;
	std::stack<tree_t *> s;
	while(root || s.empty() == false) {
		while(root) {
			s.push(root);
			root = root->left;
		}
		root = s.top();
		if(prev && root->data > prev->data)
			return false;
		s.pop();
		root = root->right;
	}
	return true;
}
bool treeIsBstREC(tree_t *root)
{
	bool bst = true;
	static tree_t *prev = NULL;
	if (!root)
	{
		return true;
	}
	bst = treeIsBstREC(root->left);
	if(prev && root->data > prev->data)
		return false;
	prev = root;
	bst = treeIsBstREC(root->right);
	return bst;
}
bool treeBstIsBalanced(tree_t *root)
{
	int lh, rh;
	if (!root)
	{
		return true;
	}
	lh = treeHeightREC(root->left);
	rh = treeHeightREC(root->right);
	if(abs(lh - rh) > 1)
		return false;
	return treeBstIsBalanced(root->left) && treeBstIsBalanced(root->right);
}
//Helper
bool treeBstIsBalancedREC(tree_t *root, bool *balanced)
{
	int lh = 0, rh = 0;
	if (!root)
	{
		return true;
	}
	lh += treeBstIsBalancedREC(root->left);
	lh += treeBstIsBalancedREC(root->right);
	if (abs(lh-rh) > 1)
	{
		return false;
	}
	if (lh > rh)
	{
		*balanced = false;
		return lh+1;
	} else {
		return rh+1;
	}
}
bool treeBstIsBalancedREC(tree_t *root)
{
	bool balanced = true;
	treeBstIsBalancedREC(root, &balanced);
	return balanced;
}
bool treeIsMirror(tree_t *root1, tree_t *root2){}
bool treeIsMirrorREC(tree_t *root1, tree_t *root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	else if (root1 == NULL || root2 == NULL)
		return false;
	return (root1->data == root2->data) && 
		treeIsMirrorREC(root1->left, root2->right) && 
			treeIsMirrorREC(root1->right, root2->left);
}
bool treeIsCopy(tree_t *root1, tree_t *root2){}
bool treeIsCopyREC(tree_t *root1, tree_t *root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	else if (root1 == NULL || root2 == NULL)
		return false;
	return (root1->data == root2->data) && 
		treeIsCopyREC(root1->left, root2->left) && 
			treeIsCopyREC(root1->right, root2->right);
}

int treeHeight(tree_t *root)
{
	int lh = 0, rh = 0;
	tree_t *p = root;
	while(p){
		if (p->left)
		{
			p = p->left;
		}else {
			p = p->right;
		}
		lh++;
	}
	p = root;
	while(p){
		if (p->right)
		{
			p = p->right;
		}else {
			p = p->left;
		}
		rh++;
	}
	if (lh > rh)
	{
		return lh;
	} else {
		return rh;
	}
	return 0;
}
int treeHeightREC(tree_t *root)
{
	int lh = 0, rh = 0;
	if (!root)
	{
		return 0;
	}
	lh += treeHeightREC(root->left);
	rh += treeHeightREC(root->right);
	if (lh > rh)
	{
		return lh+1;
	} else {
		return rh+1;
	}
}
int treeNodeCount(tree_t *root)
{
	int count = 0;
	tree_t *curr = root;
	std::stack<tree_t *> s;
	while(curr || s.empty() == false) {
		while(curr) {
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		count++;
		s.pop();
		curr = curr->right;
	}
	return count;
}
int treeNodeCountREC(tree_t *root)
{
	int count = 0;
	if (!root)
	{
		return 0;
	}
	count += treeNodeCountREC(root->left);
	count += treeNodeCountREC(root->right);
	return count+1;
}
int treeLeafCount(tree_t *root)
{
	int count = 0;
	tree_t *curr = root;
	std::stack<tree_t *> s;
	while(curr || s.empty() == false) {
		while(curr) {
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		if (!curr->left || !curr->right){
			//std::cout << curr->data << std::endl;
			count++;
		}
		s.pop();
		curr = curr->right;
	}
	return count;
}
int treeLeafCountREC(tree_t *root)
{
	int count = 0;
	if (!root)
	{
		return 0;
	}
	count = treeNodeCountREC(root->left);
	count = treeNodeCountREC(root->right);
	if (!root->left && !root->right)
	{
		return count+1;
	}
	return count;
}