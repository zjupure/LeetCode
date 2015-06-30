class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> table;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(table.count(nums[i]) > 0)
                return true;
            table.insert(nums[i]);
        }
        
        return false;
    }
};