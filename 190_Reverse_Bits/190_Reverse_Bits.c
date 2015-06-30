uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    int cnt = 32;
    
    while(n)
    {
        if(n&0x01)
        {
            res = (res<<1)|0x01;
        }
        else
        {
            res = (res<<1);
        }
        n = n>>1;
        cnt--;
    }
    res = res<<cnt;
    
    return res;
}