class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset;
        
        genCombSum(subset, 1, 0, k, 0, n);
        
        return ans;
    }
    
    void genCombSum(vector<int>& subset, int val, int curSelect, int TotalSelect, int curSum, int target)
    {
        if(curSelect == TotalSelect)
        {
            if(curSum == target)
            {
                ans.push_back(subset);
                return;
            }
            else
                return;
        }
        else if(curSum >= target || val >= 10)
            return;
        
        
        subset.push_back(val);
        genCombSum(subset, val+1, curSelect+1, TotalSelect, curSum + val, target);
        subset.pop_back();
        
        genCombSum(subset, val+1, curSelect, TotalSelect, curSum, target);
    }
};