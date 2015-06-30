bool isIsomorphic(char* s, char* t) {
    int hash_tb[256];
    int used[256];
    int i = 0;
    
    memset(hash_tb,-1,sizeof(hash_tb));
    memset(used,0,sizeof(used));
    while(s[i] != '\0' && t[i] != '\0')
    {
        if(hash_tb[s[i]] == -1)
        {
            if(!used[t[i]])
            {
                hash_tb[s[i]] = t[i];
                used[t[i]] = 1;
            }
            else
                return false;
        }
        else
        {
            if(hash_tb[s[i]] != t[i])
                return false;
        }
        i++;
    }
    
    if(s[i] != '\0' || t[i] != '\0')
        return false;
    
    return true;
    
}