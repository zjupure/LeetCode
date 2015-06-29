class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<pair<int, int> > updateNums;
        vector<int> subsets;
        
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i < candidates.size(); i++)
        {
            updateNums.push_back(make_pair(candidates[i], target/candidates[i]));
        }
        
        genCombination(updateNums, subsets, 0, 0, target);
        
        return ans;
    }
    
    void genCombination(vector<pair<int, int> >& updateNums, vector<int>& subsets, int cur, int curSum, int target)
    {
        if(curSum == target)
        {
            ans.push_back(subsets);
            return;
        }
        else if(curSum > target || cur == updateNums.size())
            return;
            
        pair<int, int> sub = updateNums[cur];
        int val = sub.first, cnt = sub.second;
        
        genCombination(updateNums, subsets, cur+1, curSum, target);
        for(int i = 1; i <= cnt; i++)
        {
            subsets.push_back(val);
            curSum += val;
            genCombination(updateNums, subsets, cur+1, curSum, target);
        }
        
        for(int i = 1; i <= cnt; i++)
            subsets.pop_back();
    }
};