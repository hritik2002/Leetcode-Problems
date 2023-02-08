class Solution {
public:
    vector<int> dp;
    int dfs(vector<int>& nums, int ind) {
        if(ind >= nums.size() - 1) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        
        int ans = INT_MAX;
        
        for(int i = nums[ind]; i > 0; i--) {
            ans = min(ans, dfs(nums, ind + i));
        }
        
        return dp[ind] = ans == INT_MAX ? ans : ans + 1;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);
        return dfs(nums, 0);
    }
};