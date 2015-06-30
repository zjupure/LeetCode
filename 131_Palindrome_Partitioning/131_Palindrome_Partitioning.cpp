class Solution {
    vector<vector<string> > ans;
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));
        vector<string> substr;
        
        for(int i = 0; i < s.size(); i++)
        {
            dp[i][i] = 1;
            if(i+1 < s.size() && s[i] == s[i+1])
                dp[i][i+1] = 1;
        }
        
        for(int k = 2; k < s.size(); k++)
        {
            for(int i = 0; i < s.size() && i + k < s.size(); i++)
            {
                if(dp[i+1][i+k-1] && s[i] == s[i+k])
                    dp[i][i+k] = 1;
            }
        }
        
        dfs(dp, substr, s, 0);
        
        return ans;
    }
    
    void dfs(vector<vector<int> >& dp, vector<string>& substr, string s, int pos)
    {
        if(pos == s.size())
        {
            ans.push_back(substr);
            return;
        }
        
        for(int i = pos; i < s.size(); i++)
        {
            if(dp[pos][i])
            {
                substr.push_back(s.substr(pos, i-pos+1));
                dfs(dp, substr, s, i+1);
                substr.pop_back();
            }
        }
    }
};