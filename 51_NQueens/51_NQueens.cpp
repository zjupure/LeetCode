class Solution {
    vector<vector<string> > ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> config(n, 0);
        
        dfs(config, 0);
        
        return ans;
    }
    
    
    void dfs(vector<int>& config, int cur)
    {
        if(cur == config.size())
        {
            vector<string> board(config.size(), string(config.size(), '.'));
            
            for(int i = 0; i < config.size(); i++)
            {
                board[i][config[i]] = 'Q';
            }
            
            ans.push_back(board);
            return;
        }
        
        for(int j = 0; j < config.size(); j++)
        {
            config[cur] = j;   // cur row fill in the j col
            bool isOk = true;
            
            //check for collision
            for(int i = 0; i < cur; i++)
            {
                if(config[i] == config[cur] || config[i] - config[cur] == i - cur || config[i] - config[cur] == cur - i)
                {
                    isOk = false;
                    break;
                }
            }
            
            if(isOk)
                dfs(config, cur+1);
        }
    }
    
};