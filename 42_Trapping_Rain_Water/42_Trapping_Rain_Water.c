int trap(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int sum = 0, curSum;
    
    curSum = 0;
    for(int i = 0; i < heightSize; i++)
    {
        curSum += height[i];
        if(height[i] >= height[left] && i != left)
        {
            sum += (i - left + 1)*height[left] - (curSum - (height[i] - height[left]));
            left = i;
            curSum = height[i];
        }
    }
    
    curSum = 0; 
    for(int i = heightSize - 1; i >= left; i--)
    {
        curSum += height[i];
        if(height[i] >= height[right] && i != right)
        {
            sum += (right - i + 1)*height[right] - (curSum - (height[i] - height[right]));
            right = i;
            curSum = height[i];
        }
    }
    
    return sum;
}