int titleToNumber(char* s) {
    int sum = 0;
    
    for(int i = 0; s[i] != '\0'; i++)
    {
        sum = sum*26 + (s[i] - 'A' + 1);
    }
    
    return sum;
}