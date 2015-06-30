int countPrimes(int n) {
    if(n <= 2)
        return 0;
    if(n == 3)
        return 1;
    
    bool *prime = (bool *)malloc(sizeof(bool)*n);
    int count = n-2;
    int rt = sqrt(n);
    
    for(int i = 0; i < n; i++)
        prime[i] = 1;
        
    for(int i = 2; i <= rt; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j < n; j += i)
            {
                if(prime[j])
                {
                    prime[j] = 0;
                    count--;  // kick out the products
                }
            }
        }
    }
    free(prime);
    
    return count;
}