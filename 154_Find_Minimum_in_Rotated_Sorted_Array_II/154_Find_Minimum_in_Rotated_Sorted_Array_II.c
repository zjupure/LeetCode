int findMin(int* nums, int numsSize) {
    int low = 0, high = numsSize-1, mid;
    
    while(low < high)
    {
        if(nums[low] < nums[high])
            return nums[low];
        
        mid = (low+high)/2;
        if(nums[low] == nums[high])
        {
            if(nums[mid] < nums[high])
            {
                high = mid;
            }
            else if(nums[mid] > nums[high])
            {
                low = mid;
            }
            else
            {
                int k = mid+1;
                while(k < high && nums[k] == nums[mid]) k++;
                if(k < high)
                {
                    low = k;
                }
                else
                {
                    high = mid;
                }
                k = mid-1;
                while(k > low && nums[k] == nums[mid]) k--;
                if(k > low)
                {
                    high = k;
                }
                else
                {
                    low = mid;
                }
            }
        }
        else
        {
            if(nums[mid] >= nums[low])
            {
                low = mid+1;
            }
            else if(nums[mid] <= nums[high])
            {
                high = mid;
            }
        }
    }
    
    return nums[low];
}