void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int m = matrixRowSize, n = matrixColSize;
    int *row = (int *)malloc(sizeof(int)*m);
    int *col = (int *)malloc(sizeof(int)*n);
    
    memset(row, 0, sizeof(int)*m);
    memset(col, 0, sizeof(int)*n);
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = col[j] = 1;
            }
        }
    }
    //set to zero
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(row[i] == 1 || col[j] == 1)
                matrix[i][j] = 0;
        }
    }
}