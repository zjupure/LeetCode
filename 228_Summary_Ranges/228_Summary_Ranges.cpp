class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        stringstream sstr;
        string range;
        
        if(nums.size() <= 0)  return ans;
        
        int start = 0;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] + 1 != nums[i+1])
            {
                // process the string
                sstr.clear();
                if(i == start)
                    sstr<<nums[start];
                else
                    sstr<<nums[start]<<"->"<<nums[i];
                
                sstr>>range;
                ans.push_back(range);
                
                start = i+1;
            }
        }
        
        sstr.clear();
        if(start == nums.size()-1)
            sstr<<nums[start];
        else
            sstr<<nums[start]<<"->"<<nums[nums.size()-1];
        
        sstr>>range;
        ans.push_back(range);
        
        return ans;
    }
};