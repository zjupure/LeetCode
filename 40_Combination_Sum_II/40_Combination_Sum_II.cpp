class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        vector<pair<int, int> > updateNums;
        int cnt = 1;
        
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size() - 1; i++)
        {
            if(candidates[i] != candidates[i+1])
            {
                updateNums.push_back(make_pair(candidates[i], cnt));
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        updateNums.push_back(make_pair(candidates[candidates.size()-1], cnt));
        
        genCombSum(updateNums, subset, 0, 0, target);
        
        return ans;
    } 
    
    
    void genCombSum(vector<pair<int, int> >& nums, vector<int>& subset, int cur, int curSum, int target)
    {
        if(curSum == target)
        {
            ans.push_back(subset);
            return;
        }
        else if(curSum > target || cur == nums.size())
            return;
        
        pair<int, int> sub = nums[cur];
        int val = sub.first, cnt = sub.second;
        
        genCombSum(nums, subset, cur+1, curSum, target);
        for(int i = 1; i <= cnt; i++)
        {
            subset.push_back(val);
            curSum += val;
            genCombSum(nums, subset, cur+1, curSum, target);
        }
        
        for(int i = 1; i <= cnt; i++)
            subset.pop_back();
    }
};