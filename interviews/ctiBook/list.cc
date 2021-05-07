#include "globalheader.h"

list_t *listInsert(list_t *root, int data)
{
	list_t *p = NULL, *q = NULL;
	list_t *node = (list_t *)malloc(sizeof(list_t));
	node->data = data;
	node->next = NULL;
	if(!root){
		return node;
	} else {
		if(data < root->data){
			node->next = root;
			return node;
		} else {
			p = root;
			while(p){
				if(data <= p->data) {
					q->next = node;
					node->next = p;
					return root;
				}
				q = p;
				p = p->next;
			}
			q->next = node;
		}
	}
	return root;
}

list_t *listDelete(list_t *root, int data)
{
	list_t *p = NULL, *q = NULL;
	if(!root){
		return root;
	} else {
		if (data == root->data)
		{
			p = root;
			root = root->next;
			free(p);
			return root;
		} else {
			p = root;
			while(p){
				if (data == p->data)
				{
					q->next = p->next;
					free(p);
					return root;
				}
				q = p;
				p = p->next;
			}
			std::cout << "data " << data << "not found " << std::endl;
		}
	}
	return root;
}
list_t *listDelete(list_t *root)
{
	list_t *p = NULL;
	while(root) {
		p = root;
		root = root->next;
		free(p);
	}
	return NULL;
}
list_t *listDeleteREC(list_t *root)
{
	if (!root)
	{
		return root;
	}
	listDeleteREC(root->next);
	free(root);
	return NULL;
}
list_t *listPrint(list_t *root)
{
	while(root) {
		std::cout << " " << root->data;
		root = root->next;
	}
	std::cout << std::endl;
	return root;
}
list_t *listPrintREC(list_t *root)
{
	if (!root)
	{
		return root;
	}
	std::cout << " " << root->data;
	listPrintREC(root->next);
	return root;
}
list_t *listReverse(list_t *root)
{
	list_t *p = NULL, *q = NULL, *r = NULL;
	p = root;
	while(p){
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	return r;
}
list_t *listReverseREC(list_t *root)
{
	list_t *p = NULL;
	if (!root || !root->next)
	{
		return root;
	}
	p = listReverseREC(root->next);
	root->next->next = root;
	root->next = NULL;
	return p;
}
list_t *listReverseWithNPair(list_t *root, int n)
{
	list_t *p = NULL, *q = NULL, *r = NULL;
	int count = 0;
	if (!root)
	{
		return root;
	}
	p = q = root;
	while(p && count < n) {
		q = p->next;
		p->next = r;
		r = p;
		p = q;
		count++;
	}
	if (p)
		root->next = listReverseWithNPair(q, n);
	return r;
}
list_t *listReverseAlternateWithNPair(list_t *root, int n)
{
	list_t *p = NULL, *q = NULL, *r = NULL;
	int count = 0;
	if (!root)
	{
		return root;
	}
	p = q = root;
	while(p && count < n) {
		q = p->next;
		p->next = r;
		r = p;
		p = q;
		count++;
	}
	count = 0;
	if (p)
		root->next = p;
	while (p && count < n-1) {
		p = p->next;
		count++;
	}
	if (p)
		p->next = listReverseAlternateWithNPair(p->next, n);
	return r;
}
list_t *listMiddle(list_t *root)
{
	int count = 0;
	list_t *mid = NULL;
	while(root) {
		if(!count)
			mid = root;
		else if(count%2 == 0)
			mid = mid->next;

		count++;
		root = root->next;
	}
	return mid;
}
list_t *listBubbleSort(list_t *root)
{
	list_t *p = NULL, *q = NULL;
	p = q = root;
	int data;
	bool swapped;
	do{
		swapped = false;
		q = p->next;
		while(q){
			if (q->data < p->data)
			{
				data = p->data;
				p->data = q->data;
				q->data = data;
				swapped = true;
			}
			q = q->next;
		}
		p = p->next;
	}while(swapped);
	return root;
}
list_t *listSelectSort(list_t *root)
{
	list_t *p = NULL, *q = NULL, *min = NULL;
	p = q = root;
	while(p){
		min = p;
		q = p->next;
		while(q){
			if (q->data < min->data)
			{
				min = q;
			}
			q = q->next;
		}
		if(min != p){
			int data = p->data;
			p->data = min->data;
			min->data = data;
		}
		p = p->next;
	}
	return root;
}
list_t *listInsertSort(list_t *root)
{
	
}
list_t *listFindDup(list_t *root)
{
	list_t *p = NULL, *prev = NULL;
	if (!listIsSorted(root))
	{
		root = listBubbleSort(root);
	}
	p = root;
	while(p) {
		if (prev && p->data == prev->data)
		{
			return p;
		}
		prev = p;
		p = p->next;
	}
	return NULL;
}
list_t *listFindLoop(list_t *root)
{
	list_t *p = NULL, *q = NULL;
	p = root;
	q = p->next;
	while(p && q){
		if(p == q)
			return p;
		p = p->next;
		if (q->next)
		{
			q = q->next->next;
		} else {
			q = q->next;
		}
	}
	return NULL;
}
list_t *listCopy(list_t *root)
{
	list_t *p = NULL, *newlist = NULL;
	list_t *node = NULL;
	while(root){
		node = (list_t *)malloc(sizeof(list_t));
		node->data = root->data;
		node->next = NULL;
		if (!newlist)
		{
			newlist = node;
			p = newlist;
		} else {
			p->next = node;
			p = p->next;
		}
		root = root->next;
	}
	return newlist;
}
list_t *listCopyREC(list_t *root)
{
	list_t *p = NULL;
	if (root)
	{
		p = (list_t *)malloc(sizeof(list_t));
		p->data = root->data;
		p->next = NULL;
		p->next = listCopyREC(root->next);
	}
	return p;
}
list_t *listFindNthNodeFromEnd(list_t *root, int n)
{
	list_t *p = root, *q = NULL;
	int count = listCount(root);
	if (count < n)
	{
		return NULL;
	}
	q = listFindNthNode(root , count-n+1);
	while(q){
		//::cout << p->data << "--" << q->data << std::endl;
		p = p->next;
		q = q->next;
	}
	return p;
}
list_t *listFindNthNode(list_t *root, int n)
{
	int count = 1;
	while(root && count < n){
		root = root->next;
		count++;
	}
	if (root)
	{
		return root;
	}
	return NULL;
}


bool listIsSorted(list_t *root)
{
	list_t *prev = NULL;
	while(root) {
		if(prev && (prev->data > root->data)) {
			return false;
		}
		prev = root;
		root = root->next;
	}
	return true;
}
bool listIsSortedREC(list_t *root)
{
	bool ret;
	if(!root){
		return true;
	}
	static list_t *prev = NULL;
	if (prev && prev->data > root->data) {
		return false;
	}
	prev = root;
	ret = listIsSortedREC(root->next);
	return ret;
}
bool listCompare(list_t *root1, list_t *root2)
{
	while(root1 && root2) {
		if(root1->data != root2->data){
			return false;
		}
		root1 = root1->next;
		root2 = root2->next;
	}
	if(root1 || root2)
		return false;
	return true;
} 
bool listCompareREC(list_t *root1, list_t *root2)
{
	bool ret = true;
	if(!root1 && !root2){
		return true;
	} else if ((root1 && root2) && (root1->data != root2->data)){
		return false;
	} 
	ret = listCompareREC(root1->next, root2->next);
	//std::cout << ret << " " << root1->data << " " << root2->data <<std::endl;
	return ret;
}

int listCount(list_t *root)
{
	int count = 0;
	while(root){
		count++;
		root = root->next;
	}
	return count;
}
int listCountREC(list_t *root)
{
	int count = 0;
	if (!root)
	{
		return 0;
	}
	count += listCountREC(root->next);
	return count+1;
}






list_t *listSpiltAlternate(list_t *root, list_t **list1, list_t **list2)
{
	list_t *p = NULL, *q = NULL;
	if (*list1 || *list2) {
		return root;
	}
	for (int i = 0; root != NULL ; i++,root = root->next)
	{
		if (i%2 == 0) {
			if (!*list1) {
				*list1 = root;
				p = root;
			} else {
				p->next = root;
				p = p->next;
			}
		} else {
			if (!*list2) {
				*list2 = root;
				q = root;
			} else {
				q->next = root;
				q = q->next;
			}
		}
	}
	if (p)
		p->next = NULL;
	if (q)
		q->next = NULL;

	return NULL;	
}
list_t *listMergeAlternate(list_t *list1, list_t *list2)
{
	list_t *p = NULL, *q = NULL, *r = NULL;
	int count = 0;
	if (!list1 && !list2) {
		return NULL;
	} else if (list1 == NULL) {
		return list2;
	} else if (list2 == NULL) {
		return list1;
	} 
	while (1) {
		if (count == 0) {
			p = q = list1;
		} else {
			if (list2) {
				r = list2;
				list2 = list2->next;
				r->next = p->next;
				p->next = r;

				r = r->next;
				if(r && r->next == NULL) {
					r->next = list2;
					//return q;
					break;
				}
				p = r;
			} else {
				//return q;
				break;
			}
		}
		count++;
	}
	return q;
}
list_t *listMergeSorted(list_t *list1, list_t *list2)
{
	list_t *p = NULL, *q = NULL, *r;
	if (!list1 && !list2) {
		return NULL;
	} else if (list1 == NULL) {
		return list2;
	} else if (list2 == NULL) {
		return list1;
	}
	p = list1;	
	while(list2 != NULL) {
		p = list1;
		r = list2;
		list2 = list2->next;
		if (r->data <= list1->data) {
			r->next = list1;
			list1 = r;
		} else {
			while (p && r->data > p->data ) {
				q = p;
				p = p->next;
			}
			r->next = p;
			q->next = r;
		}
	}
	return list1;
}
list_t *listFindIntersect(list_t *list1, list_t *list2)
{
	list_t *p = NULL, *q = NULL;
	if (list1 == NULL || list2 == NULL)
	{
		return NULL;
	}
	p = list1;
	q = list2;
	while (p && q) {
		//std::cout << "Comparing " << p->data << " ---" << 
		//					q->data  << std::endl;
		if (p == q)
		{
			return p;
		}
		p = p->next;
		q = q->next;
		if (p == NULL)
		{
			p = list2;
			list2 = NULL; //re assign only once
		}
		if (q == NULL)
		{
			q = list1;
			list1 = NULL; //re assign only once
		}
	}
	return NULL;	
}

list_t *listFindRemoveElements(list_t *list1, list_t *list2)
{
	
}
list_t *listCircularNShift(list_t *root, int n)
{
	list_t *p = NULL, *q = NULL, *r = NULL;
	q = root;
	p = listFindNthNode(root, n);
	if (!p)
		return root;
	while (p->next) {
		r = q;
		q = q->next;
		p = p->next;
	}
	p->next = root;
	r->next = NULL;
	return q;
}

bool listHasCycle(list_t *root)
{
	std::set <list_t *> set;
	while (root) {
		if (set.find(root) != set.end())
			return true;
		set.insert(root);
		root = root->next;
	}
	return false;
}

list_t *listRemoveDups(list_t *root)
{
	list_t *p = NULL, *q = NULL;
	std::set <int> set;
	if (!root)
	{
		return root;
	}
	p = root;
	listPrint(p);
	while (p) {
		if (set.find(p->data) != set.end())
		{
			//std::cout << "Deleteing " << p->data  << std::endl;
			q->next = p->next;
			free(p);
			p = q->next;
		} else {
			set.insert(p->data);
			q = p;
			p = p->next;
		}
	}
	return root;	
}
//https://www.techiedelight.com/rearrange-linked-list-alternating-high-low-values/
list_t *listMakeAlternateLowHigh(list_t *root)
{
	list_t *p = NULL, *q = NULL;
	int tmp;
	if (!root)
	{
		return root;
	}
	q = root;
	p = root->next;
	while(p) {
		if (p->data > q->data) {
			tmp = p->data;
			p->data = q->data;
			q->data = tmp;
		}

		if (p->next && p->data < p->next->data)
		{
			tmp = p->data;
			p->data = p->next->data;
			p->next->data = tmp;
		}
		
		q = p->next;
		if (q)
		{
			p = q->next;
		} else {
			p = NULL;
		}
	}
	return root;
}
list_t *listSeparateOddEven(list_t *root)
{
	list_t *p = NULL, *q = NULL, *even = NULL, *odd = NULL, *ohead = NULL;
	if (!root)
	{
		return root;
	}
	p = root;
	while(p) {
		//std::cout << p->data << std::endl;
		if (p->data%2 == 0) {
			if (!even)
				even = p;
			q = p;
			p = p->next;
		}
		else {
			if(!odd) {
				ohead = odd = p;
			} else {
				odd->next = p;
				odd = odd->next;
			}
			if(q) {
				q->next = p->next;
					
			}
			p = p->next;
		}
	}
	q->next = ohead;
	odd->next = NULL;
	return even;
}