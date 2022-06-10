class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>dp(nums.size(),0);
        int max_sum = nums[0] ;
        dp[0] = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            dp[i] = nums[i] + max(dp[i-1],0);
            max_sum = max(dp[i],max_sum);
        }
        return max_sum;
        
        
    }
};