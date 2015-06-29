int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    int m = gridRowSize, n = gridColSize;
    int *dp = (int *)malloc(sizeof(int)*n);      // optimized for the extra memory
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)
                dp[j] =  grid[i][j];
            else if(i == 0)
                dp[j] = dp[j-1] + grid[i][j];
            else if(j == 0)
                dp[j] = dp[j] + grid[i][j];
            else
            {
                if(dp[j] < dp[j-1])
                    dp[j] = dp[j] + grid[i][j];
                else
                    dp[j] = dp[j-1] + grid[i][j];
            }
        }
    }
    
    return dp[n-1];
}