/*
 *  x & (x-1): remove the low bit 1 of x
 *  eg: x = 10101100, x-1 = 10101011
 *  x & (x-1) = 10101000
 */
int hammingWeight(uint32_t n) {
    int num = 0;
    while(n)
    {
        num++;
        n &= n-1;
    }
    return num;
}