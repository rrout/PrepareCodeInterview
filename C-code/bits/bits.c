#include <stdio.h>
#include <stdlib.h>

#include "bits.h"

int bitsUtilPrintBinary(int var)
{
    int i;
    printf("Binary of(%d) : ", var);
    for (i = sizeof(var)*8-1; i >= 0; i--)
    {
        if (var & (1 << i)) {
            printf("%d", 1);
        } else
        {
            printf("%d", 0);
        }
    }
    printf("\n");
    return 1;
}
int bitsUtilFindPositionOfFirstSetBit(int var)
{
    int i;
    for (i = 0; i < sizeof(var); i++)
    {
        if (var & (1 << i))
            return i;
    }
    return -1;
}
/*
Parity is number set bits in a number
Parity is evan = if number of 1s is even
Parity is odd  = if number of 1s is odd
*/
int bitsUtilParity(int var)
{
    int parity = 0;
    while (var) {
        parity = !parity;
        var = var & (var - 1);
    }
    return parity;
}
int bitsUtilCountBits(int var)
{
    int count = 0;
    while (var) {
        count += (var & 0x1);
        var = var >> 1;
    }
    return count;
}
int bitsUtilNestPowerOf2(int var)
{
    while (var & (var - 1)) {
        var = var & (var -1);
    }
    return var << 1;
}
int bitsUtilSwapBits(int var, int bitx, int bity)
{
    int tmp1, tmp2;
    tmp1 = var & (1 << bitx);
    tmp2 = var & (1 << bity);

    // Reset the bitx and bity
    var ^= tmp1 << bitx;
    var ^= tmp2 << bity;

    //Make bit x as tmp2 and bity as tmp1
    var |= tmp1 << bity;
    var |= tmp2 << bitx;
        
    return var;
}
int bitsUtilIsPowerOf4(int var)
{
    int count = 0;
    if (var & (var - 1)) {
        while (var) {
            count++;
            var = var >> 1;
        }
        if (count & 1)
            return 0;
        else
            return 1;
    }
    return 0;
}
int bitsUtilIsPowerOfX(int var, int x)
{
    if (var & (var - 1)) {
        return ((var % (x-1) == 1));
    }
    return 0;
}
int bitsUtilCircularClockWiseShiftNbits(int var, int n)
{
    return ((var >> 3) && (var << (sizeof(var) - n)));
}