int numDecodings(char* s) {
    if(s == NULL || *s == '\0' || *s == '0')
        return 0;
    
    int x0 = 1, x1 = 1, x2 = 0;
    char last = '0';
    
    for(int i = 0; s[i] != '\0'; i++)
    {
        //continue two zeros
        if(last == '0' && s[i] == '0')
            return 0;
        
        if(last == '0')
        {
            x2 = x1;
        }
        else if(s[i] == '0')
        {
            if(last >= '3')
                return 0;
            else
                x2 = x0;
        }
        else
        {
            if(last >= '3' || (last == '2' && s[i] >= '7'))
                x2 = x1;
            else
                x2 = x0 + x1;
        }
        
        x0 = x1;
        x1 = x2;
        last = s[i];
    }
    
    return x2;
}