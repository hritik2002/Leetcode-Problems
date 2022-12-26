class Solution {
public:
    vector<bool> dp;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, false);
        
        for(int i = n - 1; i >= 0; i--) {
            int tmp = nums[i];
            if(tmp + i >= n - 1) {
                dp[i] = true;
                continue;
            }
            
            bool flag = false;
            while(tmp) {
                if(dp[i + tmp]) {
                    dp[i] = true;
                    flag = true;
                    break;
                }
                
                tmp--;
            }
            
            if(flag) continue;
            dp[i] = false;
        }
        
        return dp[0];
    }
};