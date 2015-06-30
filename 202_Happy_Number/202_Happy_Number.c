bool isHappy(int n) {
    int set[1000];
    int sum;
    
    memset(set,0,sizeof(set));
    while(true)
    {
        sum = 0;
        while(n)
        {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        
        if(sum == 1)
            return true;
        
        if(set[sum])   //has show up, deap loop
            return false;
        
        n = sum;
        set[sum] = 1;
    }
    
}