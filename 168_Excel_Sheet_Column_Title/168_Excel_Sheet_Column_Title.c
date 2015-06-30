//char rep[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

char* convertToTitle(int n) {
    char *ret = (char *)malloc(sizeof(char)*(32));
    int len = 0;
    
    while(n >= 1)
    {
        //ret[len++] = rep[(n-1)%26];
        ret[len++] = (n-1)%26 + 'A';
        n = (n-1)/26;
    }
    ret[len] = '\0';
    
    int begin = 0, end = len-1;
    while(begin < end)
    {
        int tmp = ret[end];
        ret[end] = ret[begin];
        ret[begin] = tmp;
        begin++;end--;
    }
    
    return ret;
}