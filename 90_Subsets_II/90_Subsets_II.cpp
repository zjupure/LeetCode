class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<pair<int, int> > counter;
        int cnt = 1;
        
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                counter.push_back(make_pair(nums[i-1],cnt));
                cnt = 1;
            }
            else
                cnt++;
        }
        counter.push_back(make_pair(nums[nums.size()-1],cnt));
        
        gensubSet(subset,counter,0);
        
        return ans;
    }
    
    void gensubSet(vector<int> &subset, const vector<pair<int, int> > &nums, int cur)
    {
        if(cur == nums.size())
        {
            ans.push_back(subset);
            return;
        }
        
        pair<int, int> sub = nums[cur];
        int val = sub.first, cnt = sub.second;
        
        gensubSet(subset, nums, cur+1);
        for(int i = 1; i <= cnt; i++)
        {
            subset.push_back(val);
            gensubSet(subset,nums,cur+1);
        }
        
        for(int i = 1; i <= cnt; i++)
            subset.pop_back();
    }
};