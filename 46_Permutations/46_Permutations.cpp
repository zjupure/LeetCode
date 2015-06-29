class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        genPermute(nums,0);
        
        return ans;
    }
    
    void genPermute(vector<int> &nums, int begin)
    {
        if(begin == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++)
        {
            swap(nums[i], nums[begin]);
            genPermute(nums,begin+1);
            swap(nums[i], nums[begin]);
        }
    }
};