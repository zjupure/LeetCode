class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rowRes(rowIndex+1);
        
        for(int i = 0; i <= rowIndex; i++)
        {
            for(int j = i; j >= 0; j--)
            {
                if(j == 0 || j == i)
                {
                    rowRes[j] = 1;
                }
                else
                {
                    rowRes[j] += rowRes[j-1];
                }
            }
        }
        
        return rowRes;
    }
};