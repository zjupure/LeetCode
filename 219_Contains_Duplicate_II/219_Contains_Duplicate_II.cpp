class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> numset;
        int i = 0, j = 0;
        
        // process the first k element
        while(j < nums.size() && j < i + k)
        {
            if(numset.count(nums[j]))
                return true;
            else
                numset.insert(make_pair(nums[j], j));
            j++;
        }
        
        // keep the gap between i and j is k
        while(j < nums.size())
        {
            
            
            if(numset.count(nums[j]))
                return true;
            else
                numset.insert(make_pair(nums[j], j));
            
            j++;
            numset.erase(nums[i]);
            i++;
        }
        
        return false;
    }
};