class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, INT_MAX));
        dp[0][0] = 0;
        
        for(int i = 1; i <= m; i++) {
            dp[0][i] = dp[0][i - 1] + (int)b[i - 1];
        }
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + (int)a[i - 1];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                dp[i][j] = min(dp[i][j - 1] + (int)b[j - 1], dp[i - 1][j] + (int)a[i - 1]);
            }
        }

        return dp[n][m];
    }
};