#include <stdio.h>
#include <stdlib.h>
#ifndef __RINGBUFF_H__
#define __RINGBUFF_H__
typedef struct _ringbuff_s {
	int *buf;
	int bufsize;
	int write;
	int read;
	int currsize;
}ringbuff_t;
typedef enum ringbuff_ret_s
{
	RINFBUFF_OK,
	RINFBUFF_FAIL,
	RINFBUFF_ERR_FULL,
	RINFBUFF_ERR_EMPTY,
	RINFBUFF_ERR_INTERNAL
}ringbuff_ret_t;
ringbuff_t *ringbuffInit(int size);
ringbuff_t *ringbuffDestroy(ringbuff_t *buf);
ringbuff_ret_t rinfbuffDump(ringbuff_t *buf);
ringbuff_ret_t rinfbuffEnqueue(ringbuff_t *buf, int item);
ringbuff_ret_t rinfbuffDequeue(ringbuff_t *buf, int *item);
ringbuff_ret_t rinfbuffIsFull(ringbuff_t *buf);
ringbuff_ret_t rinfbuffIsEmpty(ringbuff_t *buf);
ringbuff_ret_t rinfbuffSetRead(ringbuff_t *buf);
ringbuff_ret_t rinfbuffSetWrite(ringbuff_t *buf);

#endif