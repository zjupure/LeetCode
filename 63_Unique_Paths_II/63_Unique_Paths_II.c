/* Dynamic Programming
 * dp[i][j] = dp[i-1][j] + dp[i][j-1];  map[i][j] == 0
 *          = 0;   map[i][j] == 1
 */
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int m = obstacleGridRowSize, n = obstacleGridColSize;
    int *dp = (int *)malloc(sizeof(int)*n);
    
    memset(dp, 0, sizeof(int)*n);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!obstacleGrid[i][j])
            {
                if(i == 0 && j == 0)
                    dp[j] = 1;
                else if(j > 0)
                    dp[j] += dp[j-1];
            }
            else
                dp[j] = 0;
        }
    }
    
    return dp[n-1];
}