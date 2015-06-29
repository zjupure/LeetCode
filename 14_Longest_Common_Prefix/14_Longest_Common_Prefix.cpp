class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        
        if(strs.size() <= 0)
            return ans;
            
        ans = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            ans = getCommonPrefix(ans, strs[i]);
        }
        
        return ans;
    }
    
    /* get the common prefix of two string*/
    string getCommonPrefix(string s1, string s2)
    {
        string ret;
        int i = 0;
        
        while(i < s1.size() && i < s2.size())
        {
            if(s1[i] == s2[i])
                ret.push_back(s1[i]);
            else
                break;
            
            i++;
        }
        
        return ret;
    }
};