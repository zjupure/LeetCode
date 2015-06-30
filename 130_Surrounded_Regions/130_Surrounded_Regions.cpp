class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() <= 0)  return;
        
        int m = board.size(), n =board[0].size();
        
        for(int j = 0; j < n; j++)
        {
            if(board[0][j] == 'O')
                bfs(0,j,board);
            if(board[m-1][j] == 'O')
                bfs(m-1,j,board);
        }
        
        for(int i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
                bfs(i,0,board);
            if(board[i][n-1] == 'O')
                bfs(i,n-1,board);
        }
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'Y')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void bfs(int x, int y, vector<vector<char> >& board)
    {
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,-1,0,1};
        deque<pair<int,int> > corq;
        
        board[x][y] = 'Y';
        corq.push_back(make_pair(x,y));
        while(!corq.empty())
        {
            pair<int, int> pos = corq.front();
            corq.pop_front();
            x = pos.first, y = pos.second;
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'O')
                {
                    board[nx][ny] = 'Y';
                    corq.push_back(make_pair(nx,ny));
                }
            }
        }
    }
};