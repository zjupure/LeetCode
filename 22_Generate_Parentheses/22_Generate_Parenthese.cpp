class Solution {
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        string s(2*n,'\0');
        ans.clear();
        genBracket(s, n, 0, 0);
        
        return ans;
    }
    
    void genBracket(string &s, int n, int left, int right)
    {
        int cur = left+right;
        if(cur == 2*n)
        {
            ans.push_back(s);
            return;
        }
        
        if(left < n)
        {
            s[cur] = '(';
            genBracket(s, n, left+1, right);
            if(right < left)
            {
                s[cur] = ')';
                genBracket(s, n, left, right+1);
            }
        }
        else
        {
            s[cur] = ')';
            genBracket(s,n,left,right+1);
        }
    }
};