#include <stdio.h>
#include <stdlib.h>

#ifndef __BITS_H__
#define __BITS_H__

#define BITSUTIL_SET_BIT(data, bit)			(data[bit/32] |= (1 << (bit%32)))
#define BITSUTIL_RESET_BIT(data, bit)		(data[bit/32] &= ~(1 << (bit%32)))
#define BITSUTIL_BIT_IS_SET(data, bit)		(data[bit/32] & (1 << (bit%32)))
#define BITSUTIL_BIT_IS_CLEAR(data, bit)	!BITSUTIL_BIT_IS_SET(data, bit)
#define BITSUTIL_BIT_TOGGLE(data, bit)		(data[bit/32] ^= (1 << (bit%32)))
/*
XOR is so unique
val ^ val = clear all bits in val
val ^ 1<<n = toggle nth bit
val ^ 3 <<n = toggle 2 bits from n

000   111      000   111
000   000      111   111
---- -----    ----- -----
000   111      111   000
So XOR ing anything with 0 will be unmodified
   XOR ing anything with 1 will be its reverse value
*/
#define BITSUTIL_SET_ALL_BITS(data, size)	{\
												int i; \
												for (i = 0; i < size; ++i)\
												{\
													data[i/32] = ~0;\
												}\
											}
#define BITSUTIL_CLEAR_ALL_BITS(data, size)	{\
												int i; \
												for (i = 0; i < size; ++i)\
												{\
													data[i/32] ^= data[i/32];\
												}\
											}


#define BITSUTIL_SIZEOF_VAR(var) 		(size_t) ((char *)(&var+1) - (char *)(&var))
#define BITSUTIL_SIZEOF_TYPE(type)		(size_t) ((type *)0+1)
#define BITSUTIL_OFFSETOF(struct, elem)	(size_t) (((struct *)(0))->elem)

#endif