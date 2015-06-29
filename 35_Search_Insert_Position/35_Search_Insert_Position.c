int searchInsert(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize-1;
    int mid;
    
    while(low <= high)
    {
        if(nums[low] > target)
            return low;
        if(nums[high] < target)
            return high+1;
        
        mid = low + (high-low)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            high = mid-1;
        else
            low = mid+1;
    }
}