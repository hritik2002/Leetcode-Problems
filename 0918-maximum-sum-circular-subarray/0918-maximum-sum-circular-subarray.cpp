class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0, currMin = 0, maxsum = nums[0], minsum = nums[0], total = 0;
        
        for(auto n : nums) {
            currMax = max(currMax, 0) + n;
            currMin = min(currMin, 0) + n;
            maxsum = max(maxsum, currMax);
            minsum = min(minsum, currMin);
            total += n;
        }
        
        if(total == minsum) {
            return maxsum;
        }
        
        return max(maxsum, total - minsum);
    }
};