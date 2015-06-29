class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int isValid = true;
        
        for(int type = 0; type < 3 && isValid; type++)
        {
            for(int id = 0; id < 9 && isValid; id++)
            {
                isValid = isValidSudo(board, id, type);
            }
        }
        
        return isValid;
    }
    
    
    bool isValidSudo(vector<vector<char> >& board, int id, int type)
    {
        int valid[10];
        memset(valid, 0,sizeof(valid));
        
        if(type == 0)   // sub-box
        {
            int sx = (id/3) * 3, sy = (id%3) * 3;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(board[sx+i][sy+j] == '.')
                        continue;
                    else if(valid[board[sx+i][sy+j] - '0'] == 1)
                        return false;
                    else
                        valid[board[sx+i][sy+j] - '0'] = 1;
                }
            }
        }
        else if(type == 1)  // row
        {
            for(int j = 0; j < board.size(); j++)
            {
                if(board[id][j] == '.')
                        continue;
                if(valid[board[id][j] - '0'] == 1)
                    return false;
                else
                    valid[board[id][j] - '0'] = 1;
            }
        }
        else  // col
        {
            for(int i = 0; i < board.size(); i++)
            {
                if(board[i][id] == '.')
                        continue;
                if(valid[board[i][id] - '0'] == 1)
                    return false;
                else
                    valid[board[i][id] - '0'] = 1;
            }
        }
        
        return true;
    }
};