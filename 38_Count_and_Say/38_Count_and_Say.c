char *NextString(char *s)
{
    int len = strlen(s);
    char *ret = (char *)malloc(sizeof(char)*2*(len+1));
    int start = 0, num, cnt, i = 0;
    
    memset(ret, 0, sizeof(char)*2*(len+1));
    for(i = 1; s[i] != '\0'; i++)
    {
        if(s[i] != s[i-1])
        {
            cnt = i - start;
            num = s[start] - '0';
            sprintf(ret, "%s%d%d", ret, cnt, num);
            start = i;
        }
    }
    
    cnt = i - start;
    num = s[start] - '0';
    sprintf(ret, "%s%d%d", ret, cnt, num);
    
    return ret;
}


char* countAndSay(int n) {
    char *s = (char *)malloc(sizeof(char)*2);
    char *ret;
    
    memset(s, 0, sizeof(char)*2);
    s[0] = '1';
    
    while(--n)
    {
        ret = NextString(s);
        free(s);
        s = ret;
    }
    
    return s;
}