#include <stdio.h>
#include <stdlib.h>

#ifndef __SLIST__H__
#define __SLIST__H__

typedef struct _slist_s {
	int data;
	struct _slist_s *next;
}slist_t;

slist_t *slistAddNode(slist_t *root, int data);
slist_t *slistDelNode(slist_t *root, int data);
slist_t *slistShow(slist_t *root);
#endif //__SLIST__H__
