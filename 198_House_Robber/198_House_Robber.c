/* Dynamic Programming
 * f(j) indicates the robber has make a decision for the jth house for the maximum profit
 * so the recursion expression is f(j) = max(f(j-1), f(j-2)+nums[j]) 
 */

#define max(x,y)  (((x)>(y))?(x):(y))
int rob(int* nums, int numsSize) {
    int x0 = 0, x1 = 0, x2 = 0;
    
    //f(j) = max(f(j-1),f(j-2)+nums[j])
    for(int i = 0; i < numsSize; i++)
    {
        x2 = max(x0+nums[i],x1);
        x0 = x1;
        x1 = x2;
    }
    
    return x2;
}