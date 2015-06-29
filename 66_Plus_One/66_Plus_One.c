int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ret = (int *)malloc(sizeof(int)*(digitsSize+1));
    int ci = 1, i;
    *returnSize = digitsSize+1;
    
    for(i = digitsSize-1; i >= 0; i--)
    {
        ret[i+1] = (digits[i] + ci)%10;
        ci = (digits[i] + ci)/10;
    }
    ret[i+1] = ci;
    
    if(ci == 0)
    {
        *returnSize = digitsSize;
        ret = ret + 1;
    }
    
    return ret;
}