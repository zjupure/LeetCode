int findMin(int* nums, int numsSize) {
    int low = 0, high = numsSize-1;
    int mid;
    
    while(low < high)
    {
        mid = low + ((high-low)>>1);
        if(nums[mid] >= nums[low] && nums[mid] <= nums[high])
            return nums[low];
        else if(nums[mid] >= nums[low] && nums[mid] >= nums[high])
            low = mid+1;
        else
            high = mid;
    }
    
    return nums[low];
}