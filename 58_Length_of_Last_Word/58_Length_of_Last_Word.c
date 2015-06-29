int lengthOfLastWord(char* s) {
    int len = 0;
    int start = 0;
    int begin = 0;
    int i;
    
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] != ' ')
        {
            if(!start)
            {
                start = 1;
                begin = i;
            }
            
        }
        else if(start)
        {
            start = 0;
            len = i - begin;
        }
    }
    
    if(start)
        len = i-begin;
    
    return len;
}