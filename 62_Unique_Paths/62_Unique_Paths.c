/* Dynamic Programming 
 * dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * optimized to a vector
 */
int uniquePaths(int m, int n) {
    int *dp = (int *)malloc(sizeof(int)*n);
    
    dp[0] = 1;
    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(i == 0)
                dp[j] = 1;
            else
                dp[j] += dp[j-1];
        }
    }
    
    return dp[n-1];
}