#define min(x,y)   ((x)<(y))?(x):(y)
#define max(x,y)   ((x)>(y))?(x):(y)
int maxArea(int* height, int heightSize) {
    int low = 0, high = heightSize - 1;
    int h, maxA = 0;
    
    while(low < high)
    {
        h = min(height[low], height[high]);
        maxA = max(maxA, h*(high - low));
        
        while(low < high && height[low] <= h)
            low++;
        while(low < high && height[high] <= h)
            high--;
    }
    
    return maxA;
}