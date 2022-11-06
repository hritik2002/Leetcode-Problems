class Solution {
public:
    int dp[71][71][71];
    int solve(vector<vector<int>> &grid, int i, int j1, int j2) {
        if(i >= grid.size() || j1 >= grid[0].size() || j2 >= grid[0].size() || i < 0 || j1 < 0 || j2 < 0) {
            return 0;
        }
        
        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        
        int rr = solve (grid , i+1 , j1+1 , j2+1);
        int lr = solve (grid , i+1 , j1-1 , j2+1);
        int ll = solve (grid , i+1 , j1-1 , j2-1);
        int rl = solve (grid , i+1 , j1+1 , j2-1);
        int ls = solve (grid , i+1 , j1-1 , j2);
        int sl = solve (grid , i+1 , j1 , j2-1);
        int rs = solve (grid , i+1 , j1+1 , j2);
        int sr = solve (grid , i+1 , j1 , j2+1);
        int ss = solve (grid , i+1 , j1 , j2);
        vector<int>v={ss, rr,ll,rl,lr,rs,sr,ls,sl};                                
        
        return dp[i][j1][j2] = *max_element(v.begin(), v.end()) + (j1 != j2 ? grid[i][j1] + grid[i][j2] : grid[i][j2]);
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        
        return solve(grid, 0, 0, grid[0].size() - 1);
    }
};