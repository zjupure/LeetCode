int patition(int *nums, int low, int high)
{
    int pivot = nums[low];
    int i = low, j = high;
    
    while(i < j)
    {
        while(i < j && nums[j] >= pivot)
            j--;
        nums[i] = nums[j];
        
        while(i < j && nums[i] <= pivot)
            i++;
        
        nums[j] = nums[i];
    }
    
    nums[i] = pivot;
    
    return i;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int low = 0, high = numsSize-1, index;
    
    k = numsSize - k;
    index = patition(nums, low, high);
    while(index != k)
    {
        if(index > k)
            high = index - 1;
        else
            low = index + 1;
        
        index = patition(nums, low, high);
    }
    
    return nums[index];
}