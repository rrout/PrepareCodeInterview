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
slist_t *slistReverseREC(slist_t *root);
slist_t *slistFindNthNode(slist_t *root, int n);
slist_t *slistSearch(slist_t *root, int data);
slist_t *slistSearchREC(slist_t *root, int data);
slist_t *slistCopy(slist_t *root);
slist_t *slistDestroy(slist_t *root);
slist_t *slistDestroyREC(slist_t *root);
slist_t *slistFindMiddle(slist_t *root);
slist_t *slistReverseKnodes(slist_t *root, int k);
slist_t *slistHasDupsSorted(slist_t *root);
slist_t *slistHasDups(slist_t *root);
slist_t *slistRemoveDupsSorted(slist_t *root);
slist_t *slistRemoveDups(slist_t *root);
slist_t *slistRotateAt(slist_t *root, int k);
slist_t *slistDeleteLactOccur(slist_t *root, int num);
slist_t *slistSort(slist_t *root);
slist_t *slistMergeSorted(slist_t *root1, slist_t *root2);
slist_t *slistMergeAlternare(slist_t *root1, slist_t *root2);
#endif //__SLIST__H__
