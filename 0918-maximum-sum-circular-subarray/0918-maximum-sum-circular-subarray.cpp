class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, maxSum = nums[0], minSum = nums[0], currMax = 0, currMin = 0;
        
        for(auto num : nums) {
            currMax = max(currMax + num, num);
            maxSum = max(maxSum, currMax);
            currMin = min(currMin + num, num);
            minSum = min(minSum, currMin);
            total += num;
        }
        if(total - minSum == 0) return maxSum;
        
        return max(maxSum, total - minSum);
    }
};