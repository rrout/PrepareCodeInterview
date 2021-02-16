
#include <stdio.h>
#include <stdlib.h>
#include "ringbuff.h"
ringbuff_t *ringbuffInit(int size)
{
	ringbuff_t * buff = NULL;
	int *itembuf = NULL;
	buff = (ringbuff_t *)malloc(sizeof(ringbuff_t));
	if (!buff) return NULL;
	itembuf = (int *)malloc(size * (sizeof(int)));
	if (!itembuf) return NULL;

	buff->buf = itembuf;
	buff->bufsize = size;
	buff->write = buff->read = 0;
	buff->currsize = 0;

	return buff;
}
ringbuff_t *ringbuffDestroy(ringbuff_t *buf)
{
	if (buf)
	{
		free(buf->buf);
		free(buf);
	}
	return NULL;
}
ringbuff_ret_t rinfbuffDump(ringbuff_t *buf)
{
	if (buf)
	{
		printf("%s: Buffer %p\n", __FUNCTION__, buf->buf);
		printf("%s: Buffer size %d\n", __FUNCTION__, buf->bufsize);
		printf("%s: Buffer write %d\n", __FUNCTION__, buf->write);
		printf("%s: Buffer read %d\n", __FUNCTION__, buf->read);
		printf("%s: Buffer count %d\n", __FUNCTION__, buf->currsize);
		return RINFBUFF_OK;
	}
	return RINFBUFF_FAIL;
}
ringbuff_ret_t rinfbuffEnqueue(ringbuff_t *buf, int item)
{
	if (rinfbuffIsFull(buf) == RINFBUFF_OK)
	{
		printf("%s : Buffer Full\n", __FUNCTION__);
		return RINFBUFF_ERR_FULL;
	} else {
		buf->buf[buf->write] = item;
		rinfbuffSetWrite(buf);
	}
	return RINFBUFF_OK;
}
ringbuff_ret_t rinfbuffDequeue(ringbuff_t *buf, int *item)
{
	if (rinfbuffIsEmpty(buf) == RINFBUFF_OK)
	{
		printf("%s : Buffer Empty\n", __FUNCTION__);
		return RINFBUFF_ERR_EMPTY;
	} else {
		*item = buf->buf[buf->read];
		rinfbuffSetRead(buf);
	}
	return RINFBUFF_OK;
}
ringbuff_ret_t rinfbuffIsFull(ringbuff_t *buf)
{
	if (buf)
	{
		if (buf->currsize == buf->bufsize)
		{
			return RINFBUFF_OK;
		} else {
			return RINFBUFF_FAIL;
		}
	}
	return RINFBUFF_ERR_INTERNAL;
}
ringbuff_ret_t rinfbuffIsEmpty(ringbuff_t *buf)
{
	if (buf)
	{
		if (buf->currsize == 0)
		{
			return RINFBUFF_OK;
		} else {
			return RINFBUFF_FAIL;
		}
	}
	return RINFBUFF_ERR_INTERNAL;
}
ringbuff_ret_t rinfbuffSetRead(ringbuff_t *buf)
{
	if (buf)
	{
		if (buf->currsize != 0)
		{
			buf->read = (buf->read +1)%buf->bufsize;
			buf->currsize--;
			return RINFBUFF_OK;
		} else {
			return RINFBUFF_FAIL;
		}
	}
	return RINFBUFF_FAIL;
}
ringbuff_ret_t rinfbuffSetWrite(ringbuff_t *buf)
{
	if (buf)
	{
		buf->write = (buf->write +1)%buf->bufsize;
		buf->currsize++;
		return RINFBUFF_OK;
	}
	return RINFBUFF_FAIL;
}

int main(int argc, char const *argv[])
{
	int item;
	ringbuff_t *ringbuffer = ringbuffInit(15);
	rinfbuffEnqueue(ringbuffer, 1);
	rinfbuffEnqueue(ringbuffer, 2);
	rinfbuffEnqueue(ringbuffer, 3);
	rinfbuffEnqueue(ringbuffer, 4);
	rinfbuffEnqueue(ringbuffer, 5);
	rinfbuffEnqueue(ringbuffer, 6);
	rinfbuffEnqueue(ringbuffer, 7);
	rinfbuffDump(ringbuffer);
	rinfbuffEnqueue(ringbuffer, 8);
	rinfbuffDump(ringbuffer);
	rinfbuffEnqueue(ringbuffer, 9);
	rinfbuffEnqueue(ringbuffer, 10);
	rinfbuffEnqueue(ringbuffer, 11);
	rinfbuffEnqueue(ringbuffer, 11);
	rinfbuffEnqueue(ringbuffer, 11);
	rinfbuffDump(ringbuffer);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDump(ringbuffer);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDump(ringbuffer);
	rinfbuffDequeue(ringbuffer, &item);
	rinfbuffDump(ringbuffer);
	ringbuffDestroy(ringbuffer);
	return 0;
}