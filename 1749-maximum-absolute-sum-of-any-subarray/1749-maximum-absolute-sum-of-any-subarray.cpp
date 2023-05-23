class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currSum = INT_MIN, ans = 0;
        int minSum = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            currSum = max(0, currSum) + nums[i];
            minSum = min(0, minSum) + nums[i];
            
            ans = max({ans, currSum, abs(minSum)});
        }
        
        return ans;
    }
};