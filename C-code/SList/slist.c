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
slist_t *slistCopy(slist_t *root, slist_t *newroot)
{

}
slist_t *slistFindMiddle(slist_t *root)
{

}
slist_t *slistReverseKnodes(slist_t *root, int k)
{

}
slist_t *slistHasDups(slist_t *root)
{

}
slist_t *slistRemoveDups(slist_t *root)
{

}

int main()
{
	slist_t *root = NULL;
	slist_t *tmp= NULL;

	root = slistAddNode(root, 111);
	root = slistAddNode(root, 112);
	root = slistAddNode(root, 101);

	root = slistDelNode(root, 11);

	slistShow(root);
	slistShowReverse(root);

	root = slistReverse(root);
	slistShow(root);

	tmp = slistFindNthNode(root,2);
	printf("%d\n", tmp->data);

	tmp = slistSearch(root,101);
	printf("%d\n", tmp->data);
	
	tmp = slistSearchREC(root,101);
	printf("%d\n", tmp->data);

	return 1;
}



