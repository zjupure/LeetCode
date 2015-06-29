//recursive version
/*int getCode(int n)
{
    if(n == 0 || n == 1)
        return n;
    
    int m = n;
    while(m&(m-1) != 0)
    {
        m = m&(m-1);
    }
    
    return m | getCode(2*m-n-1);
}*/

// ret[i] = ret[i-1]^(i&(-i));
int* grayCode(int n, int* returnSize) {
    int size = 1<<n;
    int *ret = (int *)malloc(sizeof(int)*size);
    int m;
    
    ret[0] = 0;
    for(int i = 1; i < size; i++)
    {
        /*m = i;
        while((m&(m-1)) != 0)
        {
            m = m&(m-1);
        }
        
        ret[i] = m | ret[2*m-i-1];*/
        ret[i] = ret[i-1]^(i&(-i));
    }
    
    *returnSize = size;
    return ret;
}