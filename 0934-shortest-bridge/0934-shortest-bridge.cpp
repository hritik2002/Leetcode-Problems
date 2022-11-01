class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    queue<pair<int, int>> q;
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) {
            return;
        }
        
        grid[i][j] = 2;
        q.push({i, j});
        
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
        
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bool flag = false;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
        
        int d = 0, minDist = INT_MAX;
        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                auto top = q.front();
                q.pop();
                
                for(auto __dir : dir) {
                    int x = top.first + __dir[0];
                    int y = top.second + __dir[1];
                    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 2) {
                        continue;
                    }else if(grid[x][y] == 0) {
                        q.push({x, y});
                        grid[x][y] = 2;
                    }else minDist = min(minDist, d);
                    
                }
            }
            
            d++;
        }
        
        return minDist == INT_MAX ? 0 : minDist;
    }
};