/* Dynamic Programming 
 * Fibonacci sequence: f(n) = f(n-1) + f(n-2)
 */
int climbStairs(int n) {
    int x0 = 0, x1 = 1, x2 = 0;
    
    while(n--)
    {
        x2 = x0 + x1;
        x0 = x1;
        x1 = x2;
    }
    
    return x2;
}