int reverse(int x) {
    int MAXINT = ~(1<<31);
    int ret = 0;
    int sign = (x>=0)?1:-1;
    
    if(x == (1<<31))
        return 0;
    
    x = sign*x;
    while(x)
    {
        //overflow
        if(ret > MAXINT/10)
            return 0;
        
        ret = ret*10 + (x%10);
        x /= 10;
    }
    
    return sign*ret;
}