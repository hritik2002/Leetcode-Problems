class Solution {
public:
    int dp[201][201];
    long long solve(vector<vector<int>> &grid, int i, int j, int n, int m) {
        if(i >= n || j >= m || i < 0 || j < 0) {
            return INT_MAX;
        }else if(grid[i][j] == INT_MAX) {
            return INT_MAX;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i == n - 1 && j == m - 1) {
            return grid[i][j];
        }
        
        long long tmp = grid[i][j];
        grid[i][j] = INT_MAX;
        long long d = solve(grid, i + 1, j, n, m);
        long long r = solve(grid, i, j + 1, n, m);
        
        grid[i][j] = tmp;
        
         dp[i][j] = tmp + min(d, r);
        
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int n = grid.size(), m = grid[0].size();
        int ans = solve(grid, 0, 0, n, m);
        
        return ans;
    }
};