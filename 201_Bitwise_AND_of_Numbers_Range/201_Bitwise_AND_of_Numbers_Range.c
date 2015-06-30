/* binary search to find the highest bit 1 of a number x */
int highbit(int x)
{
    int n = 0;
    
    if(x == 0)  return 0;
    
    if((x>>16)&0xffff) { x = x>>16; n += 16; }
    if((x>>8)&0xff) { x = x>>8; n += 8; }
    if((x>>4)&0x0f) { x = x>>4; n += 4; }
    if((x>>2)&0x03) { x = x>>2; n += 2; }
    if((x>>1)&0x01) { x = x>>1; n += 1; }
    
    return n;
}

/*
 *  m = xxxxx0yyyyy
 *  n = xxxxx1zzzzz
 *  m and n have the common part xxxxx, there is a number p = xxxxx100000
 *  so m&...p...&n = xxxxx000000, we just need to find the highest different bit of m and n
 *  highbit(m^n), then generate a mask to extract the common part xxxxx
 * 
 *
 */

int rangeBitwiseAnd(int m, int n) {
    int mask = m^n;
    
    mask = 0xffffffff<<highbit(mask);
    
    return m&mask;
}