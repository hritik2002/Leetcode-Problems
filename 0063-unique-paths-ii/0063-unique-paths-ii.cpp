class Solution {
public:
    int paths = 0;
    int dfs(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n) {
        if(i < 0 || j < 0 || i >= m || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if(obstacleGrid[i][j] < 0) {
            return -1 * obstacleGrid[i][j];
        }
        if(i == m - 1 && j == n - 1) {
            paths++;
            
            return 1;
        }
        
        obstacleGrid[i][j] = 1;
        
        int right = dfs(obstacleGrid, i, j + 1, m, n);
        int down = dfs(obstacleGrid, i + 1, j, m, n);
        obstacleGrid[i][j] = -1 * (right + down);
        
        return right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        return dfs(obstacleGrid, 0, 0, m, n);
        
        return paths;
    }
};