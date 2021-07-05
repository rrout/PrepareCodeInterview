#include "header.h"

list_t *listInsert(list_t *root, int data) {
	list_t *p, *q;
	list_t *node = (list_t *)malloc(sizeof(list_t));
	node->data = data;
	node->next = NULL;
	if (!root) {
		return node;
	}
	if (data < root->data) {
		node->next = root;
		return node;
	}
	p = root;
	while(p) {
		if (data < p->data) {
			node->next = p;
			q->next = node;
			return root;
		}
		q = p;
		p = p->next;
	}
	q->next = node;
	return root;
}
list_t *listDelete(list_t *root, int data) {
	list_t *p, *q;
	if (!root)
		return root;
	if (data == root->data) {
		p = root;
		root = root->next;
		return root;
	}
	p = root;
	while (p) {
		if (data == p->data) {
			q->next = p->next;
			free(p);
			return root;
		}
		q = p;
		p = p->next;
	}
	std::cout << "Data: " << data << " not found" << std::endl;
	return root;
}
list_t *listDelete(list_t *root) {
	list_t *p = NULL;
	while(root) {
		p = root;
		root = root->next;
		free(p);
	}
	return NULL;
}
list_t *listDeleteREC(list_t *root) {
	if (!root) {
		return root;
	}
	listDeleteREC(root->next);
	free(root);
	return NULL;
}
list_t *listMid(list_t *root) {
	list_t *mid = root;
	int count = 0;
	while (root) {
		if (count && count %2 == 0) {
			mid = mid->next;
		}
		root = root->next;
		count++;
	}
	return mid;
}
list_t *listReverse(list_t *root) {
	list_t *p = NULL, *q = NULL , *r = NULL;
	p =  root;
	while(p) {
		q = p;
		p = p->next;
		q->next = r;
		r = q;
	}
	return r;
}
list_t *listReverseREC(list_t *root) {
	list_t *p = NULL;
	if (root == NULL || root->next == NULL) {
		return root;
	}
	p = listReverseREC(root->next);
	root->next->next =  root;
	root->next = NULL;
	return p;
}
list_t *listReverseKSets(list_t *root, int k) {
	list_t *p = NULL, *q = NULL , *r = NULL;
	int count = 0;
	p =  root;
	while(p && count < k) {
		q = p;
		p = p->next;
		q->next = r;
		r = q;
		count++;
	}
	if(p)
		root->next = listReverseKSets(p, k);
	return r;
}
list_t *listReverseKSetsREC(list_t *root, int k) {




}
list_t *listReArrange(list_t *root) {
	list_t *p = NULL, *q = NULL , *r = NULL;
	std::stack<list_t *> s;
	list_t *mid = listMid(root);
	mid = mid->next;
	while(mid) {
		s.push(mid);
		mid = mid->next;
	} 
	p = root;
	while(s.empty() != true) {
		r = s.top();
		q = p->next; 
		p->next = r;
		r->next = q;

		s.pop();
		p = q;
	}
	p->next = NULL;
	return root;
}
list_t *listBubbleSort(list_t *root) {
	list_t *p = root, *q = NULL, *r;
	bool swapped = false;
	int tmp = 0;
	do {
		swapped = false;
		while(p) {
			q = p->next;
			while(q) {
				if (q->data < p->data) {
					tmp = q->data;
					q->data = p->data;
					p->data = tmp;
					swapped = true;
				}
				q = q->next;
			}
			p = p->next;
		} 
	}while(swapped);
	return root;
}
list_t *listSelectSort(list_t *root) {
	list_t *min = NULL;
	list_t *p = root, *q, *r;
	int tmp = 0;
	while(p) {
		min = p;
		q = p->next;
		while(q) {
			if (q->data < min->data)
				min = q;
			q = q->next;
		}
		if(min != p) {
			tmp  = min->data;
			min->data = p->data;
			p->data = tmp;
		}
		p = p->next;
	}
	return root;
}
list_t *listInsertSort(list_t *root) {}
list_t *listFindIntersect(list_t *l1, list_t *l2) {
	list_t *p = NULL, *q = NULL, *r = NULL;
	int pcount = 0, qcount = 0;
	if(l1 == NULL || l2 == NULL) {
		return NULL;
	}
	p = l1;
	q = l2;
	while(p && q) {
		if (p == q) {
			return p;
		}
		std::cout << p->data << "<->" << q->data << std::endl;
		p = p->next;
		q = q->next;
		if (pcount == 0 && p == NULL && q != NULL) {
			pcount++;
			p = l2;
		}
		if (qcount == 0 && q == NULL && p!= NULL) {
			qcount++;
			q = l1;
		}
	}
	return NULL;
}
list_t *listFindLoop(list_t *root) {
	list_t *p = NULL, *q = NULL, *r = NULL;
	p = root;
	q = p->next;
	if(q) q = q->next;
	r = q;
	while(p) {
		if (p == q)
			return r;

		p = p->next;
		r = q;
		q = q->next;
		if(q) {
			r = q;
			q = q->next;
		}
		//std::cout << p->data << "  " << q->data << std::endl;
	}
	return NULL;
}
list_t *listMergeSortedLists(list_t *l1, list_t *l2) {
	list_t *p = NULL, *q = NULL, *r = NULL;
	if (!listIsSorted(l1) || !listIsSorted(l2)) {
		return NULL;
	}
	if(l1 == NULL && l2 == NULL) {
		return l1;
	} else if (l1 == NULL) {
		return l2;
	} else if (l2 == NULL){
		return l1;
	} else {
		if(r == NULL) {
			if (l1->data < l2->data) {
				p = l1;
				l1 = l1->next;
			} else {
				p = l2;
				l2 = l2->next;
			}
			r = p;
		}
		while(l1 && l2) {
			if (l1->data  < l2->data) {
				p->next = l1;
				l1 = l1->next;
				p = p->next;
				p->next = NULL;
			} else {
				p->next = l2;
				l2 = l2->next;
				p = p->next;
				p->next = NULL;
			}
		}
		if (l1)
			p->next = l1;
		if (l2)
			p->next = l2;
	}
	return r;
}
list_t *listMergeUnSortedLists(list_t *l1, list_t *l2) {
	list_t *p = NULL, *q = NULL, *r = NULL;
	if(l1 == NULL && l2 == NULL) {
		return NULL;
	} else if (l1 == NULL) {
		return l2;
	} else if (l2 == NULL){
		return l1;
	} else {
		p = l1;
		while(p) {
			q = p;
			p = p->next;
		}
		q->next = l2;
	}
	return l1;
}


void listPrint(list_t *root) {
	std::cout << "List : ";
	while(root) {
		std::cout << root->data <<  "  ";
		root = root->next;
	}
	std::cout << std::endl;
}
void listPrintREC(list_t *root) {
	if (!root)
	{
		std::cout << std::endl;
		return;
	}
	std::cout << root->data <<  "  ";
	listPrintREC(root->next);
}

int listCountNodes(list_t *root) {
	int count = 0;
	while(root) {
		count++;
		root = root->next;
	}
	return count;
}
int listCountNodesREC(list_t *root) {
	int count = 0;
	if (!root) {
		return 0;
	}
	count += listCountNodesREC(root->next);
	return count+1;
}

bool listIsSorted(list_t *root) {
	list_t *p = root, *prev = NULL;
	while(p) {
		if(prev && prev->data > p->data)
			return false;
		p = p->next;
	}
	return true;
}
bool listIsSortedREC(list_t *root, list_t *prev) {
	bool sorted = true;
	if (!root) {
		return true;
	}
	sorted &= listIsSortedREC(root->next, root);
	if(prev && prev->data > root->data)
		return false;
	return sorted;
}
bool listIsPalindrome(list_t *root) {
	list_t *p = root, *q = NULL;
	std::stack<list_t *> s;
	list_t *mid = listMid(root);
	int count = listCountNodes(root);
	if (count) {
		if (count%2 != 0) {
			mid = mid->next;
		}
	} else {
		return false;
	}
	while(mid) {
		s.push(mid);
		mid = mid->next;
	}
	while(s.empty() != true) {
		q = s.top();
		s.pop();
		if (p->data != q->data) {
			return false;
		}
		p = p->next;
	}
	return true;
}
