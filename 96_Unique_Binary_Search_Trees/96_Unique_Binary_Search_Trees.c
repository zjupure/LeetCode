// f[n] = sum(f(i)*f(n-1-i)) i = 0...n-1
int numTrees(int n) {
    if(n == 1)  return 1;
    
    int *num = (int *)malloc(sizeof(int)*(n+1));
    
    num[0] = 1; num[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        int sum = 0;
        for(int j = 0; j < i; j++)
        {
            sum += num[j]*num[i-1-j];
        }
        num[i] = sum;
    }
    
    return num[n];
}