class Solution {
public:
    vector<vector<int>> dp;
    int getDistance(string a, string b, int n, int m) {
        if(n <= 0) {
            return m;
        }
        if(m <= 0) {
            return n;
        }
        if(dp[n][m] != INT_MAX) {
            return dp[n][m];
        }

        if(a[n - 1] == b[m - 1]) {
            dp[n][m] = getDistance(a, b, n - 1, m - 1);
        }else {
            dp[n][m] = min(getDistance(a, b, n, m - 1), getDistance(a, b, n - 1, m)) + 1;
        }

        return dp[n][m];
    }

    int minDistance(string a, string b) {
        int n = a.length(), m = b.length();
        dp.resize(n + 1, vector<int> (m + 1, INT_MAX));
        dp[0][0] = 0;

        dp[n][m] = getDistance(a, b, n, m);

        return dp[n][m];
    }
};