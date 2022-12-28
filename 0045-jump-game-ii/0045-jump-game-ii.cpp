class Solution {
public:
    vector<int> dp;
    int stepsToReach(vector<int> &nums, int index) {
        if(index >= nums.size() - 1) {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        int steps = nums[index];
        int ans = INT_MAX;
        while(steps) {
            ans = min(ans, stepsToReach(nums, index + steps)); // take
            steps--;
        }
        
        return dp[index] = ans == INT_MAX ? INT_MAX : ans + 1;
    }
    int jump(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        
        return stepsToReach(nums, 0);
    }
};