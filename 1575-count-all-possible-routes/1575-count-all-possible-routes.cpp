class Solution {
public:
    vector<vector<int>> dp;
    int mod = 1e9 + 7;
    int countPossibleRoutes(vector<int>& locations, int start, int finish, int fuel) {
        if(fuel < 0) {
            return 0;
        }
        
        int cnt = 0;
        if(dp[start][fuel] != -1) {
            return dp[start][fuel];
        }
        if(start == finish) {
            cnt++;
        }
        
        int res = 0;
        for(int i = 0; i < locations.size(); i++) {
            if(i == start) continue;
            
            res += countPossibleRoutes(locations, i, finish, fuel - abs(locations[start] - locations[i]));
            res %= mod;
        }
        
        return dp[start][fuel] = (res + cnt) % mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        dp.resize(101, vector<int> (201, -1));
        return countPossibleRoutes(locations, start, finish, fuel);        
    }
};