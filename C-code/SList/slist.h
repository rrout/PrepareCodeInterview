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
slist_t *slistShowReverse(slist_t *root);
slist_t *slistReverse(slist_t *root);
slist_t *slistFindNthNode(slist_t *root, int n);
slist_t *slistSearch(slist_t *root, int data);
slist_t *slistCopy(slist_t *root, slist_t *newroot);
slist_t *slistFindMiddle(slist_t *root);
slist_t *slistReverseKnodes(slist_t *root, int k);
slist_t *slistHasDups(slist_t *root);
slist_t *slistRemoveDups(slist_t *root);
#endif //__SLIST__H__
