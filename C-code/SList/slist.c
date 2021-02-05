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

int main()
{
	slist_t *root = NULL;

	root = slistAddNode(root, 111);
	root = slistAddNode(root, 112);
	root = slistAddNode(root, 101);

	root = slistDelNode(root, 11);
	
	slistShow(root);

	return 1;
}



