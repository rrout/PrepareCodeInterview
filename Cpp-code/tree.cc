#include "tree.h"
template <class T> tree<T>::tree(){
	treeroot = nullptr;
}

template <class T> tree<T>::~tree(){
}
/* PRIVATE FUNCTIONS */
template <class T> treenode<T> *tree<T>::insertREC(treenode<T> *root, T data){
	if(!root) {
		treenode<T> *node = new treenode<T>(data);
		return node;
	}
	if(data < root->data)
		root->left = insertREC(root->left, data);
	else
		root->right = insertREC(root->right, data);
	return root;
}
template <class T> treenode<T> *tree<T>::removeREC(treenode<T> *root, T data){}
template <class T> treenode<T> *tree<T>::removeREC(treenode<T> *root){}
template <class T> void tree<T>::print(treenode<T> *root, int n){
	if (root) {
		print(root->left, n+1);
		for (int i = 0; i < n; ++i)
		{
			std::cout << "     ";
		}
		std::cout << root->data << std::endl << std::endl;
		print(root->right, n+1);
	}
}
template <class T> void tree<T>::preorderTraverseREC(treenode<T> *root){
	if (root) {
		std::cout << " " << root->data;
		preorderTraverseREC(root->left);
		preorderTraverseREC(root->right);
	}	
}
template <class T> void tree<T>::inorderTraverseREC(treenode<T> *root){
	if (root) {
		inorderTraverseREC(root->left);
		std::cout << " " << root->data;
		inorderTraverseREC(root->right);
	}	
}
template <class T> void tree<T>::postorderTraverseREC(treenode<T> *root){
	if (root) {
		postorderTraverseREC(root->left);
		postorderTraverseREC(root->right);
		std::cout << " " << root->data;
	}	
}
template <class T> void tree<T>::levelorderTraverseREC(treenode<T> *root, int h){
	if (!root)
		return;
	levelorderTraverseREC(root->left, h-1);
	if (h == 0)
		std::cout << " " << root->data;
	levelorderTraverseREC(root->right, h-1);
}
template <class T> void tree<T>::printLeftViewREC(treenode<T> *root, int h, bool *print){
	if (!root)
		return;
	printLeftViewREC(root->left, h-1, print);
	if (h == 0 && *print == 0)
	{
		std::cout << " " << root->data;
		*print = 1;
		return;
	}
	printLeftViewREC(root->right, h-1, print);
}
template <class T> void tree<T>::printRightViewREC(treenode<T> *root, int h, T &print){
	if (!root)
		return;
	printRightViewREC(root->left, h-1, print);
	if (h == 0)
	{
		print = root->data;
		return;
	}
	printRightViewREC(root->right, h-1, print);
}
template <class T> treenode<T> *tree<T>::searchREC(treenode<T> *root, T data){
	treenode<T> *tmp = nullptr;
	if (!root)
		return root;
	if (data == root->data)
		return root;
	if (data < root->data)
		tmp = searchREC(root->left, data);
	else
		tmp = searchREC(root->right, data);
	return tmp;
}
template <class T> treenode<T> *tree<T>::minElemREC(treenode<T> *root){
	treenode<T> *tmp = nullptr;
	if (!root || !root->left )
		return root;
	if(root->left)
		tmp = minElemREC(root->left);
	else
		tmp = minElemREC(root->right);
	return tmp;
}
template <class T> treenode<T> *tree<T>::maxElemREC(treenode<T> *root){
	treenode<T> *tmp = nullptr;
	if (!root || !root->right )
		return root;
	if(root->right)
		tmp = maxElemREC(root->right);
	else
		tmp = maxElemREC(root->left);
	return tmp;
}
template <class T> treenode<T> *tree<T>::findLcaREC(treenode<T> *root, T x, T y){
	treenode<T> *llca;
	treenode<T> *rlca;
	if(!root)
		return nullptr;
	if (root->data == x || root->data == y)
		return root;
	llca = findLcaREC(root->left, x, y);
	rlca = findLcaREC(root->right, x, y);

	if(llca && rlca)
		return root;
	if(llca)
		return llca;
	else 
		return rlca;
}
template <class T> treenode<T> *tree<T>::findbstLcaREC(treenode<T> *root, T x, T y){
	treenode<T> *lca;
	if(!root)
		return nullptr;
	if(root->data < x && root->data < y)
		lca = findbstLcaREC(root->left, x, y);
	else if (root->data > x && root->data > y)
		lca = findbstLcaREC(root->right, x, y);
	else
		return root;
	return lca;
}
template <class T> int tree<T>::heightREC(treenode<T> *root){
	int lh = 0;
	int rh = 0;
	if (!root)
	{
		return 0;
	}
	lh += heightREC(root->left);
	rh += heightREC(root->right);
	if(lh > rh)
		return lh+1;
	else
		return rh+1;
}
template <class T> bool tree<T>::isBstREC(treenode<T> *root){}
template <class T> bool tree<T>::isBalancedREC(treenode<T> *root){
	int lh = 0;
	int rh = 0;
	if (!root)
	{
		return true;;
	}
	isBalancedREC(root->left);
	lh = heightREC(root->left);
	rh = heightREC(root->right);
	if(abs(lh-rh) > 1)
		return false;
	isBalancedREC(root->right);
}
template <class T> treenode<T> *tree<T>::findDeepImbalanceNodeREC(treenode<T> *root){
	treenode<T> *node = nullptr;
	int lh = 0;
	int rh = 0;
	if (!root)
	{
		return nullptr;;
	}
	node = findDeepImbalanceNodeREC(root->left);
	lh = heightREC(root->left);
	rh = heightREC(root->right);
	if(!node && abs(lh-rh) > 1)
		return root;
	else
		return node;
	node = findDeepImbalanceNodeREC(root->right);
}
template <class T>
bool tree<T>::findPathREC(treenode<T> *root, T data, std::vector<treenode<T> *> &v){
	if(!root)
		return false;
	v.push_back(root);
	if(root->data == data)
		return true;
	if(findPathREC(root->left, data, v) ||
		findPathREC(root->right, data, v)) {
		return true;
	}
	v.pop_back();
	return false;
}
template <class T>
bool tree<T>::findBstPathREC(treenode<T> *root, T data, std::vector<treenode<T> *> &v){
	bool ret = false;
	if(!root)
		return false;
	v.push_back(root);
	if (data < root->data) {
		ret = findBstPathREC(root->left, data, v);
	} else if (data > root->data){
		ret =  findBstPathREC(root->right, data, v);
	} else {
		return true;
	}
	return ret;
}


/* PUBLIC FUNCTIONS */
template <class T> void tree<T>::insert(T data){
	treenode<T> *node = new treenode<T>(data);
	treenode<T> *p = nullptr, *parent;
	if (treeroot == nullptr) {
		treeroot = node;
		return;
	}
	while(p) {
		parent = p;
		if(data <= p->data) 
			p = p->left;
		if(data > p->data)
			p = p->right;
	}
	if(data < parent->data)
		parent->left = node;
	else
		parent->right = node;
}
template <class T> void tree<T>::insertREC(T data){
	treeroot = insertREC(treeroot, data);
}
template <class T> void tree<T>::remove(T data){}
template <class T> void tree<T>::removeREC(T data){}
template <class T> void tree<T>::remove(){}
template <class T> void tree<T>::removeREC(){}
template <class T> void tree<T>::print(){
	print(treeroot, 0);
}
template <class T> void tree<T>::preorderTraverse(){
	std::cout << __func__ << ": ";
	if (!treeroot)
		return;
	std::stack<treenode<T> *> s;
	treenode<T> *curr = treeroot;
	s.push(curr);
	while(s.empty() ==false) {
		curr = s.top();
		std::cout << curr->data << " ";
		s.pop();
		if (curr->right)
			s.push(curr->right);
		if (curr->left)
			s.push(curr->left);
	}
	std::cout << std::endl;
}
template <class T> void tree<T>::preorderTraverseREC(){
	std::cout << __func__ << ":";
	preorderTraverseREC(treeroot);
	std::cout << std::endl;
}
template <class T> void tree<T>::inorderTraverse(){
	std::cout << __func__ << ": ";
	if (!treeroot)
		return;
	std::stack<treenode<T> *> s;
	treenode<T> *curr = treeroot;
	while(curr || s.empty() ==false) {
		while(curr) {
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		std::cout << curr->data << " ";
		s.pop();
		curr = curr->right;
	}
	std::cout << std::endl;
}
template <class T> void tree<T>::inorderTraverseREC(){
	std::cout << __func__ << ":";
	inorderTraverseREC(treeroot);
	std::cout << std::endl;
}
template <class T> void tree<T>::postorderTraverse(){
	std::cout << __func__ << ": ";
	if (!treeroot)
		return;
	std::stack<treenode<T> *> in;
	std::stack<treenode<T> *> out;
	treenode<T> *curr = treeroot;
	in.push(curr);
	while(in.empty() ==false) {
		curr = in.top();
		out.push(curr);
		in.pop();
		
		if (curr->left)
			in.push(curr->left);
		if (curr->right)
			in.push(curr->right);
	}

	while(out.empty() == false) {
		curr = out.top();
		std::cout << curr->data << " ";
		out.pop();
	}
	std::cout << std::endl;
}
template <class T> void tree<T>::postorderTraverseREC(){
	std::cout << __func__ << ":";
	postorderTraverseREC(treeroot);
	std::cout << std::endl;
}
template <class T> void tree<T>::levelorderTraverse(){
	std::cout << __func__ << ": ";
	if (!treeroot)
		return;
	treenode<T> *curr;
	std::queue<treenode<T> *> q;
	curr = treeroot;
	q.push(curr);
	while(q.empty() == false) {
		curr = q.front();
		std::cout << curr->data << " ";
		q.pop();
		if (curr->left)
			q.push(curr->left);
		if (curr->right)
			q.push(curr->right);
	}
	std::cout << std::endl;
}
template <class T> void tree<T>::levelorderTraverseREC(){
	std::cout << __func__ << ":";
	int height = heightREC(treeroot);
	for (int i = 0; i < height; ++i)
	{
		levelorderTraverseREC(treeroot, i);
	}
	std::cout << std::endl;
}
template <class T> void tree<T>::printLeftView(){
	std::cout << __func__ << ": ";
	if (!treeroot)
		return;
	std::queue<treenode<T> *> q;
	treenode<T> *curr = nullptr;
	q.push(treeroot);
	while(q.empty() == false) {
		int count = q.size();
		for (int i = 0; i < count; ++i)
		{
			curr = q.front();
			q.pop();
			if(i == 0)
				std::cout << curr->data << " ";
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
		}
	}
	std::cout << std::endl;
}
template <class T> void tree<T>::printLeftViewREC(){
	std::cout << __func__ << ":";
	bool print = 0;
	int height = heightREC(treeroot);
	for (int i = 0; i < height; ++i)
	{
		print = 0;
		printLeftViewREC(treeroot, i, &print);
	}
	std::cout << std::endl;
}
template <class T> void tree<T>::printRightView(){
	std::cout << __func__ << ": ";
	std::queue<treenode<T> *> q;
	treenode<T> *curr = nullptr;
	q.push(treeroot);

	while(q.empty() != true){
		int count = q.size();
		for (int i = 0; i < count; ++i)
		{
			curr = q.front();
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
			q.pop();
		}
		std::cout << " "  << curr->data;
	}
	std::cout << std::endl;
}
template <class T> void tree<T>::printRightViewREC(){
	std::cout << __func__ << ":";
	T print;
	int height = heightREC(treeroot);
	for (int i = 0; i < height; ++i)
	{
		printRightViewREC(treeroot, i, print);
		std::cout << " " << print;
	}
	std::cout << std::endl;
}
template <class T> treenode<T> *tree<T>::search(T data){
	treenode<T> *p = treeroot;
	while(p) {
		if (data < p->data)
			p = p->left;
		else if (data > p->data)
			p = p->right;
		else
			return p;
	}
	return nullptr;
}
template <class T> treenode<T> *tree<T>::searchREC(T data){
	return searchREC(treeroot, data);
}
template <class T> treenode<T> *tree<T>::minElem(){
	treenode<T> *p = treeroot;
	if (!treeroot)
		return nullptr;	
	while (p && p->left)
		p = p->left;
	return p;
}
template <class T> treenode<T> *tree<T>::minElemREC(){
	return minElemREC(treeroot);
}
template <class T> treenode<T> *tree<T>::maxElem(){
	treenode<T> *p = treeroot;
	if (!treeroot)
		return nullptr;	
	while (p && p->right)
		p = p->right;
	return p;
}
template <class T> treenode<T> *tree<T>::maxElemREC(){
	return maxElemREC(treeroot);
}
template <class T> treenode<T> *tree<T>::findLca(T x, T y){
	bool ret;
	std::vector<treenode<T> *> v1, v2;
	ret = findPathREC(x, v1);
	ret |= findPathREC(y, v2);

	if (ret)
	{
		for (unsigned int i = 0; i < v1.size(); ++i)
		{
			if (v1[i] != v2[i]) {
				if(i == 0)
					return v1[i];
				else
					return v1[i-1];
			}
		}
	}
	return nullptr;
}
template <class T> treenode<T> *tree<T>::findLcaREC(T x, T y){
	return findLcaREC(treeroot, x , y);
}
template <class T> treenode<T> *tree<T>::findBstLca(T x, T y){
	treenode<T> *p = treeroot;
	if(!treeroot)
		return treeroot;
	while(p) {
		if (p->data < x && p->data < y)
			p = p->left;
		else if (p->data > x && p->data > y)
			p = p->right;
		else
			return p;
	}
	return nullptr;
}
template <class T> treenode<T> *tree<T>::findbstLcaREC(T x, T y){
	return findbstLcaREC(treeroot, x , y);
}
template <class T> treenode<T> *tree<T>::findDeepImbalanceNodeREC(){
	return findDeepImbalanceNodeREC(treeroot);
}
template <class T>
void  tree<T>::printPath(T data){
	bool ret = false;
	std::vector<treenode<T> *> v;
	if (isBst()) {
		ret = findBstPathREC(data, v);
	} else {
		ret = findPathREC(data, v);
	}
	if (ret) {
		for (unsigned int i = 0; i < v.size(); ++i)
		{
			std::cout << "[" << v[i]->data << "] --> ";
		}
		std::cout << std::endl;
	} else {
		std::cout << "Path to " << data << " not found" << std::endl;
	}
}
template <class T>
bool tree<T>::findPathREC(T data, std::vector<treenode<T> *> &v){
	return findPathREC(treeroot, data, v);
}
template <class T>
bool tree<T>::findBstPath(T data, std::vector<treenode<T> *> &v){
	treenode<T> *p = treeroot;
	if (!treeroot)
		return false;
	while(p) {
		v.push_back(p);
		if(data < p->data)
			p = p->left;
		else if(data > p->data)
			p = p->right;
		else
			return true;
	}
	return false;
}
template <class T>
bool tree<T>::findBstPathREC(T data, std::vector<treenode<T> *> &v){
	return findBstPathREC(treeroot, data, v);
}

template <class T> int tree<T>::height(){
	treenode<T> *p;
	int lh = 0;
	int rh = 0;
	if (!treeroot)
		return 0;
	p = treeroot;
	while(p) {
		if (p->left)
			p = p->left;
		else
			p = p->right;
		lh++;
	}
	p = treeroot;
	while(p) {
		if (p->right)
			p = p->right;
		else
			p = p->left;
		rh++;
	}
	if(lh > rh)
		return lh;
	else 
		return rh;
}
template <class T> int tree<T>::heightREC(){
	return heightREC(treeroot);
}

template <class T> bool tree<T>::isBst(){
	if(!treeroot)
		return true;
	std::stack<treenode<T> *> s;
	treenode<T> *curr = treeroot, *prev = nullptr;
	while (curr || s.empty() == false) {
		while(curr) {
			s.push(curr);
			curr = curr->left;
		}

		curr = s.top();
		s.pop();

		if (prev && curr->data < prev->data)
			return false;
		prev = curr;

		curr = curr->right;
	}

	return true;
}
template <class T> bool tree<T>::isBstREC(){
	return isBstREC(treeroot);
}
template <class T> bool tree<T>::isBalanced(){}
template <class T> bool tree<T>::isBalancedREC(){
	return isBalancedREC(treeroot);
}
//Explicitly instantiate the template
template class tree<int>;
template class tree<std::string>;