class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left = bisearch(nums, target, 0);
        int right = bisearch(nums, target, 1);
        
        ans.push_back(left); ans.push_back(right);
        
        return ans;
    }
    
    /* modified binary search */
    int bisearch(vector<int>& nums, int target, int dir)
    {
        int low = 0, high = nums.size()-1, mid;
        
        while(low <= high)
        {
            if(nums[low] > target || nums[high] < target)
                return -1;
            
            mid = (low + high)>>1;
            if(nums[mid] == target)
            {
                if(dir == 0)  // left
                {
                    if(mid == 0 || nums[mid-1] < target)
                        return mid;
                    else
                        high = mid - 1;
                }
                else   // right
                {
                    if(mid == nums.size()-1 || nums[mid+1] > target)
                        return mid;
                    else
                        low = mid + 1;
                }
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return -1;
    }
};