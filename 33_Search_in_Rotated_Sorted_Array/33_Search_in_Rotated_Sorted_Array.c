int search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize-1, mid;
    
    while(low <= high)
    {
        if(nums[low] < nums[high])
        {
            if(nums[low] > target || nums[high] < target) 
                return -1;
            else
                return bisearch(nums, low, high , target);
        }
        
        mid = (low + high)>>1;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
        {
            if(nums[mid] >= nums[low])
            {
                if(nums[low] <= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        else
        {
            if(nums[mid] >= nums[low])
            {
                low = mid + 1;
            }
            else
            {
                if(nums[high] >= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
    }
    
    return -1;
}

/* binary search in sorted array*/
int bisearch(int *nums, int start, int end, int target)
{
    int low = start, high = end, mid;
    
    while(low <= high)
    {
        mid = (low + high)>>1;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return -1;
}