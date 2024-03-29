class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.length(), m = b.length();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }
        for(int i = 1; i <= m; i++) {
            dp[0][i] = i;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }else {
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                    // delete, insert, replace
                }
            }
        }

        return dp[n][m];
    }
};