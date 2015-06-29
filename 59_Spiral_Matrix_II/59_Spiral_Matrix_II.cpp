class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ret(n,vector<int>(n));
        
        int tot = 0;
        int left = 0, right = n-1, top = 0, bot = n-1;
        int i,j;
        
        while(tot < n*n)
        {
            i = top++;
            for(j = left; j <= right; j++)
                ret[i][j] = ++tot;
            j = right--;
            for(i = top; i <= bot; i++)
                ret[i][j] = ++tot;
            i = bot--;
            for(j = right; j >= left; j--)
                ret[i][j] = ++tot;
            j = left++;
            for(i = bot; i >= top; i--)
                ret[i][j] = ++tot;
        }
    
        return ret;
    }
};