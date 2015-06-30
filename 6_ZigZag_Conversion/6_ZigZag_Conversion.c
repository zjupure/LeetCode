char* convert(char* s, int numRows) {
    if(numRows == 1)
        return s;
    
    int row = 0, col = 0, gap = 0;
    int len = strlen(s), k = 0, dir = 0;
    char *res = (char *)malloc(sizeof(char)*(len+1));
    
    for(row = 0; row < numRows; row++)
    {
        dir = 1;
        for(col = row; col < len; col += gap)
        {
            res[k++] = s[col];
            if(row == 0 || row == numRows - 1)
            {
                gap = 2*(numRows - 1);
            }
            else
            {
                gap = dir ? (2*(numRows - 1 - row)) : (2*row);
                dir = !dir;
            }
        }
    }
    res[k++] = '\0';
    
    return res;
}