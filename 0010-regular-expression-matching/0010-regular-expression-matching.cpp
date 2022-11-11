class Solution {
public:
    int dp[32][32];
    bool solve(string s, string p, int i, int j, int n, int m) {
        if(j == m) {
            return i == n;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if(p[j + 1] == '*') {
            if(solve(s, p, i, j + 2, n, m)) {       // assuming * -> null
                return dp[i][j] = 1;
            }
            while(i < n && (s[i] == p[j] || p[j] == '.')) {
                if(solve(s, p, ++i, j + 2, n, m)) return dp[i][j] = 1;
            }
        }else if(i < n && (s[i] == p[j] || p[j] == '.') && solve(s, p, i + 1, j + 1, n, m)) {
            return dp[i][j] = 1;
        }
        
        return dp[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        int n = s.length(), m = p.length();
        return solve(s, p, 0, 0, n, m);
    }
};