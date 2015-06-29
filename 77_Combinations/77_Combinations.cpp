class Solution {
    vector<vector<int> > ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> comb;
        
        genComb(n,k,1,0,comb);
        
        return ans;
    }
    
    void genComb(int n, int k, int val, int cur, vector<int> &comb)
    {
        if(cur == k)
        {
            ans.push_back(comb);
            return;
        }
        
        if(val <= n)
        {
            genComb(n,k,val+1,cur,comb);
            comb.push_back(val);
            genComb(n,k,val+1,cur+1,comb);
            comb.pop_back();
        }
    }
};