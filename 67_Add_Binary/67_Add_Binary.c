char* addBinary(char* a, char* b) {
    int i = strlen(a)-1, j = strlen(b)-1;
    int k = (i>j)?i+3:j+3;
    char *ret = (char *)malloc(sizeof(char)*k);
    int ai,bi,ci = 0;
    
    ret[--k] = '\0';
    while(i >= 0 || j >= 0)
    {
        ai = (i<0)?0:(a[i--]-'0');
        bi = (j<0)?0:(b[j--]-'0');
        
        ret[--k] = (ai^bi^ci) + '0';
        ci = (ai&bi)|(ai&ci)|(bi&ci);
    }
    ret[--k] = ci + '0';
    
    if(ci == 0)
    {
        ret = ret+1;
    }
    
    return ret;
}