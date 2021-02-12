#include <stdio.h>
#include <stdlib.h>

#include "slist.h"

slist_t *slistAddNode(slist_t *root, int data)
{
	slist_t *p = NULL, *q =	NULL;
	if (!root)
	{
		root = (slist_t *) malloc(sizeof(slist_t));
		root->data = data;
		root->next = NULL;
		return root;
	}
	if (data <= root->data)
	{
		p = (slist_t *) malloc(sizeof(slist_t));
		p->data = data;
		p->next = root;
		return p;
	} else {
		p = q = root;
		while(p) {
			if (p->data > data) {
				q->next = (slist_t *) malloc(sizeof(slist_t));
				q = q->next;
				q->data = data;
				q->next = p;
				return root;
			}
			q = p;
			p = p->next;
		}
		q->next = (slist_t *) malloc(sizeof(slist_t));
		q = q->next;
		q->data = data;
		q->next = NULL;
		return root;
	}
	return root;
}


slist_t *slistDelNode(slist_t *root, int data)
{
	slist_t *p = NULL, *q =	NULL;
	if (!root)
	{
		return root;
	} else {
		if (root->data == data)
		{
			p = root;
			root = root->next;
			free(p);
			return root;
		} else {
			p = q = root;
			while(p) {
				if (p->data == data)
				{
					q->next = p->next;
					free(p);
					return root;
				}
				q = p;
				p = p->next;
			}
			printf("Data %d not found\n", data);
		}
	}
	return root;
}

slist_t *slistShow(slist_t *root)
{
	if (root)
	{
		while (root) {
			printf("Data: %d\n", root->data);
			root = root->next;
		}
	}
	return root;
}

slist_t *slistShowReverse(slist_t *root)
{
	if (!root)
	{
		return NULL;
	}
	slistShowReverse(root->next);
	printf("%d \t", root->data);
	return NULL;
}

slist_t *slistReverse(slist_t *root)
{
	slist_t *p = NULL, *q = NULL, *r = NULL;
	p = q = root;
	while(p) {
		q = p;
		p = p->next;
		q->next	= r;
		r = q;
	}
	return q;
}
slist_t *slistReverseREC(slist_t *root)
{
	slist_t *p = NULL;
	if (!root || !root->next)
		return root;
	p = slistReverseREC(root->next);
	root->next->next = root;
	root->next = NULL;
	return p;
}
slist_t *slistFindNthNode(slist_t *root, int n)
{
	int i;
	for (int i = 0; i < n; ++i)
	{
		if (root)
		{
			root = root->next;
		} else {
			return NULL;
		}
	}
	return root;
}
slist_t *slistSearch(slist_t *root, int data)
{
	while(root) {
		if (root->data == data)
		{
			return root;
		}
		root = root->next;
	}
	return NULL;
}
slist_t *slistSearchREC(slist_t *root, int data)
{
	slist_t *tmp = NULL;
	if (root && root->data == data) {
		return root;
	} else {
		tmp  = slistSearchREC(root->next, data);
	}
	return tmp;
}
slist_t *slistCopy(slist_t *root)
{
	slist_t *newroot =NULL, *p = NULL;
	if (!root)
	{
		return NULL;
	} else {
		newroot = (slist_t *) malloc(sizeof(slist_t));
		newroot->data = root->data;
		newroot->next = NULL;
		p = newroot;
		root = root->next;
		while(root) {
			p->next = (slist_t *) malloc(sizeof(slist_t));
			p = p->next;
			p->data = root->data;
			p->next = NULL;
			root = root->next;
		}
	}
	return newroot;
}

slist_t *slistDestroy(slist_t *root)
{
	slist_t *p =NULL;
	while(root) {
		p = root;
		root = root->next;
		free(p);
	}
	return NULL;
}
slist_t *slistDestroyREC(slist_t *root)
{
	if (!root)
	{
		return root;
	} else {
		slistDestroyREC(root->next);
		free(root);
	}
	return NULL;
}
slist_t *slistFindMiddle(slist_t *root)
{
	slist_t *p = NULL, *q = NULL;
	int count = 0;
	p = q = root;
	while(p) {
		if (count && (count%2) == 0)
		{
			q = q->next;
		}
		count++;
		p = p->next;
	}
	return q;
}
slist_t *slistReverseKnodes(slist_t *root, int k)
{
	slist_t *p = NULL, *q = NULL, *r = NULL;
	p = q = root;
	int count = 0;
	while(p && count < k){
		q = p;
		p = p->next;
		q->next = r;
		r = q;
		count++;
	}
	if (p)
	{
		root->next = slistReverseKnodes(p, k);
	}
	return q;
}
slist_t *slistHasDupsSorted(slist_t *root)
{
	slist_t *p = NULL, *q = NULL;
	p = q = root;
	p = p->next;
	while(p){
		if (q->data == p->data)
		{
			return q;
		}
		q = p;
		p = p->next;
	}
	return NULL;
}
slist_t *slistHasDups(slist_t *root)
{
	slist_t *p = NULL, *q = NULL;
	p = q = root;
	while(p){
		q = p->next;
		while(q){
			if (p->data == q->data)
			{
				return q;
			}
			q = q->next;
		}
		p = p->next;
	}
	return NULL;
}
slist_t *slistRemoveDupsSorted(slist_t *root)
{
	slist_t *p = NULL, *q = NULL;
	p = q = root;
	p = p->next;
	while(p){
		if (q->data == p->data)
		{
			q->next = p->next;
			free(p);
			p = q->next;
			continue;
		}
		q = p;
		p = p->next;
	}
	return root;
}

slist_t *slistRemoveDups(slist_t *root)
{
	slist_t *p = NULL, *q = NULL, *r = NULL;
	p = q = root;
	while(p){
		r = p;
		q = p->next;
		while(q){
			if (p->data == q->data)
			{
				r->next = q->next;
				free(q);
				q = r->next;
			}
			r = q;
			q = q->next;
		}
		p = p->next;
	}
	return root;
}

int main()
{
	slist_t *root = NULL;
	slist_t *tmp= NULL;

	root = slistAddNode(root, 111);
	root = slistAddNode(root, 112);
	root = slistAddNode(root, 101);
	root = slistAddNode(root, 102);
	root = slistAddNode(root, 103);
	root = slistAddNode(root, 104);
	root = slistAddNode(root, 105);
	root = slistAddNode(root, 106);
	root = slistAddNode(root, 107);
	root = slistAddNode(root, 108);
	root = slistAddNode(root, 109);
	root = slistAddNode(root, 110);

	root = slistDelNode(root, 11);

	slistShow(root);
	slistShowReverse(root);

	root = slistReverse(root);
	slistShow(root);

	root = slistReverseREC(root);
	slistShow(root);

	tmp = slistFindNthNode(root,2);
	printf("%d\n", tmp->data);

	tmp = slistSearch(root,101);
	printf("%d\n", tmp->data);
	
	tmp = slistSearchREC(root,105);
	printf("%d\n", tmp->data);

	tmp = slistCopy(root);
	slistShow(tmp);

	tmp = slistDestroy(tmp);
	slistShow(tmp);

	slistShow(root);

	tmp = slistFindMiddle(root);
	printf("%d\n", tmp->data);

	root = slistAddNode(root, 104);
	slistShow(root);

	slistRemoveDups(root);
	slistShow(root);

	tmp = slistHasDups(root);
	if (tmp)
	{
		printf("Duplicate is %d\n", tmp->data);
	} else {
		printf("List has no duplicate\n");
	}

	root = slistReverseKnodes(root, 2);
	slistShow(root);

	return 1;
}



