class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        vector<int> dp(10001, 0);
        vector<int> dist(10001, 0);
        
        for(auto num : nums) {
            dist[num] += num;
        }
        
        dp[1] = dist[1];
        dp[0] = 0;
        for(int n = 2; n <= maxi; n++) {
            dp[n] = max(dp[n - 1], dp[n - 2] + dist[n]);
        }
        
        return dp[maxi];
    }
};