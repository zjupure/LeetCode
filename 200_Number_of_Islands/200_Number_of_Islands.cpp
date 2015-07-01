class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int isLands = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    isLands++;
                    bfs(grid, i, j);
                }
            }
        }
        
        return isLands;
    }
    
    void bfs(vector<vector<char> >& grid, int x, int y)
    {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        int row = grid.size(), col = grid[0].size();
        deque<pair<int, int> > corq;
        
        
        corq.push_back(make_pair(x, y));
        grid[x][y] = 'X';
        
        while(!corq.empty())
        {
            int fx = corq.front().first, fy = corq.front().second;
            corq.pop_front();
            
            for(int i = 0; i < 4; i++)
            {
                int nx = fx + dx[i], ny = fy + dy[i];
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == '1')
                {
                    corq.push_back(make_pair(nx,ny));
                    grid[nx][ny] = 'X';
                }
            }
        }
    }
};