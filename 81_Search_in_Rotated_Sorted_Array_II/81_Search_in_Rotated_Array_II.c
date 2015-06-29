bool bisearch(int *nums, int start, int end, int target)
{
    int low = start, high = end, mid;
    
    while(low <= high)
    {
        mid = (low + high)>>1;
        if(nums[mid] == target)
            return true;
        else if(nums[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return false;
}


bool search(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize-1, mid;
    
    while(low <= high)
    {
        if(nums[low] < nums[high])
        {
            if(nums[low] > target || nums[high] < target)
                return false;
            else
                return bisearch(nums, low, high, target);
        }
        
        mid = (low + high)>>1;
        if(nums[mid] == target)
            return true;
        else if(nums[mid] > target)
        {
            if(nums[mid] >  nums[low])
            {
                if(nums[low] <= target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if(nums[mid] < nums[low])
            {
                high = mid - 1;
            }
            else
            {
                if(nums[high] < nums[low])
                    low = mid + 1;
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
                        high = mid-1;
                    }
                    k = mid-1;
                    while(k > low && nums[k] == nums[mid]) k--;
                    if(k > low)
                    {
                        high = k;
                    }
                    else
                    {
                        low = mid+1;
                    }
                }
            }
        }
        else
        {
            if(nums[mid] < nums[low])
            {
                if(nums[high] >= target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else if(nums[mid] > nums[low])
            {
                low = mid + 1;
            }
            else
            {
                if(nums[high] < nums[low])
                    high = mid - 1;
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
                        high = mid-1;
                    }
                    k = mid-1;
                    while(k > low && nums[k] == nums[mid]) k--;
                    if(k > low)
                    {
                        high = k;
                    }
                    else
                    {
                        low = mid+1;
                    }
                }
            }
        }
    }
    
    return false;
}


