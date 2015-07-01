#define max(x,y)   ((x)>(y))?(x):(y)
int rob(int* nums, int numsSize) {
    int x0, x1, x2 , x3;
    
    x0 = 0, x1 = 0, x2 = 0;
    // cal 1--->n-1  max profit
    for(int i = 0; i < numsSize-1; i++)
    {
        x2 = max(x0 + nums[i], x1);
        x0 = x1;
        x1 = x2;
    }
    
    x0 = 0, x1 = 0, x3 = 0;
    // cal 2--->n-2  max profit
    for(int i = 1; i < numsSize - 2; i++)
    {
        x3 = max(x0 + nums[i], x1);
        x0 = x1;
        x1 = x3;
    }
    
    return max(x2, x3 + nums[numsSize-1]);
}