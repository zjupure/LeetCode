double myPow(double x, int n) {
    //deal with the special cases
    if(n == 0)
        return 1;
    
    if(x == 1)
        return 1;
    
    if(x == -1)
        return (n&0x01)?-1:1;
    
    //general conditions
    double factor = x;
    double ret = 1.0;
    
    int sign = (n>=0)?1:-1;
    
    n = sign*n;
    
    while(n)
    {
        if(n&0x01)
            ret *= factor;
        factor *= factor;
        n = n>>1;
    }
    
    if(sign < 0)
        ret = 1.0/ret;
    
    return ret;
}