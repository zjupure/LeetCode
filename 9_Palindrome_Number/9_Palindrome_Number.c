bool isPalindrome(int x) {
    int tmp = x;
    long long ret = 0;
    
    while(tmp > 0)
    {
        ret = ret*10 + tmp%10;
        tmp /= 10;
    }
    
    return ret == (long long)x;
}