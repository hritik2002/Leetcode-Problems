class Solution {
public:
    int dp[51][51][51][51];
    int solve(vector<vector<int>> &grid, int r1, int c1, int r2, int c2) {
        int n = grid.size(), m = grid[0].size();
        
        if(r1 >= n || r2 >= n || c1 >= m || c2 >= m || r1 < 0 || r2 < 0 || c1 < 0 || c2 < 0) {
            return INT_MIN;
        }else if(grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return INT_MIN;
        }
        if(dp[r1][r2][c1][c2] != -1) {
            return dp[r1][r2][c1][c2];
        }
        
        if(r1 == n - 1 && c1 == m - 1) {
            return grid[r1][c1];
        }else if(r2 == n - 1 && c2 == m - 1) {
            return grid[r2][c2];
        }
        int ans = 0;
        if(r1 == r2 && c1 == c2) {
            ans = grid[r1][c1];
        }else ans = grid[r1][c1] + grid[r2][c2];
        
        int rr = solve(grid, r1, c1 + 1, r2, c2 + 1);
        int dr = solve(grid, r1 + 1, c1, r2, c2 + 1);
        int rd = solve(grid, r1, c1 + 1, r2 + 1, c2);
        int dd = solve(grid, r1 + 1, c1, r2 + 1, c2);
        
        dp[r1][r2][c1][c2] = (max({rr, dr, max(rd, dd)}) + ans);
        
        return dp[r1][r2][c1][c2];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return max(solve(grid, 0, 0, 0, 0), 0);
    }
};