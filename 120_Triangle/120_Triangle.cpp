class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> rowRes(triangle.size());
        
        for(int i = 0; i < triangle.size(); i++)
        {
            for(int j = triangle[i].size() - 1; j >= 0; j--)
            {
                if(j == i)
                    rowRes[j] = rowRes[j-1] + triangle[i][j];
                else if(j == 0)
                    rowRes[j] = rowRes[j] + triangle[i][j];
                else
                    rowRes[j] = min(rowRes[j-1], rowRes[j]) + triangle[i][j];
            }
        }
        
        int minSum = rowRes[0];
        for(int i = 1; i < rowRes.size(); i++)
            minSum = min(minSum, rowRes[i]);
        
        return minSum;
    }
};