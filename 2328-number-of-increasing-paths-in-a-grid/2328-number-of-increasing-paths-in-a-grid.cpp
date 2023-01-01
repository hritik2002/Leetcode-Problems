class Solution {
public:
    int dp[1000][1000] = {}, mod = 1e9 + 7;
    int dfs(int i, int j, vector<vector<int>>& grid, int prev) {
        if(min(i, j) < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] <= prev) {
            return 0;
        }
        
        return dp[i][j] ? : dp[i][j] = (1LL + dfs(i + 1, j, grid, grid[i][j]) + dfs(i - 1, j, grid, grid[i][j]) + dfs(i, j + 1, grid, grid[i][j]) + dfs(i, j - 1, grid, grid[i][j])) % mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res = (res + dfs(i, j, grid, 0)) % mod;
            }
        }
        
        return res;
    }
};