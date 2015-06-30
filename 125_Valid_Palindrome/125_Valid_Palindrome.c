bool isPalindrome(char* s) {
    int i, j;
    int len = 0;
    bool isOk = true;
    
    for(i = 0, j = 0; s[i] != '\0'; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
            s[j++] = s[i];
        else if(s[i] >= 'a' && s[i] <= 'z')
            s[j++] = s[i];
        else if(s[i] >= 'A' && s[i] <= 'Z')
            s[j++] = s[i] - 'A' + 'a';
    }
    len = j;
    s[j++] = '\0';
    
    i = 0, j = len-1;
    while(i < j)
    {
        if(s[i] != s[j])
        {
            isOk = false;
            break;
        }
        i++, j--;
    }
    
    return isOk;
}