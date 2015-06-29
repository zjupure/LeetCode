class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        
        sort(nums.begin(), nums.end());
        genSubset(nums, subset, 0);
        
        return ans;
    }
    
    
    void genSubset(vector<int> &nums, vector<int> &subset, int cur)
    {
        if(cur == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        
        genSubset(nums,subset, cur+1);
        subset.push_back(nums[cur]);
        genSubset(nums,subset, cur+1);
        subset.pop_back();
    }
};