class Solution {
public:
    vector<int> dp;
    bool checkCanJump(vector<int> &nums, int i, int n) {
        if(i >= n - 1) {
            return true;
        }
        if(dp[i] != -1) {
            return dp[i];
        }
        if(nums[i] >= n - 1) {
            return true;
        }
        
        int tmp = nums[i];
        while(tmp) {
            if(checkCanJump(nums, i + tmp--, n)) {
                return dp[i] = true;
            }
        }
        
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        
        return checkCanJump(nums, 0, n);
    }
};