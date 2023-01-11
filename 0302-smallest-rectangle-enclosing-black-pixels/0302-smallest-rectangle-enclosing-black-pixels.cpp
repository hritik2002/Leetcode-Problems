class Solution {
public:
    int left = INT_MAX, right = INT_MIN;
    int down = INT_MIN, up = INT_MAX;
    vector<vector<bool>> dp;
    void dfs(vector<vector<char>>& image, int x, int y, int m, int n) {
        if(x < 0 || y < 0 || x >= m || y >= n || image[x][y] == '0' || dp[x][y]) {
            return;
        }
                
        left = min(left, y);
        right = max(right, y);
        down = max(down, x);
        up = min(up, x);
        dp[x][y] = true;
        
        // recursion calls
        dfs(image, x + 1, y, m, n);
        dfs(image, x - 1, y, m, n);
        dfs(image, x, y + 1, m, n);
        dfs(image, x, y - 1, m, n);
        
        image[x][y] = '1';
        return;
    }
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        dp.resize(m, vector<bool> (n, false));
        
        dfs(image, x, y, m, n);
        
        return (right - left + 1) * (down - up + 1);
    }
};