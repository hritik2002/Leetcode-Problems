class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& arr, int ind, int time) {
        if(ind >= arr.size()) {
            return 0;
        }
        if(dp[ind][time] != INT_MIN) {
            return dp[ind][time];
        }
        
        int take = dfs(arr, ind + 1, time + 1) + time * arr[ind];
        int donttake = dfs(arr, ind + 1, time);
        
        return dp[ind][time] = max(take, donttake);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        
        dp.resize(n + 1, vector<int> (n + 2, INT_MIN));
        sort(satisfaction.begin(), satisfaction.end());
        return dfs(satisfaction, 0, 1);
    }
};