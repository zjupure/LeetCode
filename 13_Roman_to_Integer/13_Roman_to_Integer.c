int romanToInt(char* s) {
    int rep[256];
    int sum = 0;
    int last = 0;
    
    rep['I'] = 1; rep['V'] = 5; rep['X'] = 10; rep['L'] = 50; rep['C'] = 100; rep['D'] = 500; rep['M'] = 1000;
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(last == 0)
        {
            sum += rep[s[i]];
        }
        else if(last < rep[s[i]])
        {
            sum += rep[s[i]] - 2*last;
        }
        else
        {
            sum += rep[s[i]];
        }
        last = rep[s[i]];
    }
    
    return sum;
}