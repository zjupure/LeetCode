void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int n = matrixRowSize;
    int last, tmp;
    
    for(int i = 0; i < n/2; i++)
    {
        for(int j = i; j < n-1-i; j++)
        {
            //(i,j)
            int x = i, y = j;
            last = matrix[x][y];
            for(int k = 0; k < 4; k++)
            {
                tmp = matrix[y][n-1-x];
                matrix[y][n-1-x] = last;
                last = tmp;
                int t = x;
                x = y;
                y = n-1-t;
            }
        }
    }
}