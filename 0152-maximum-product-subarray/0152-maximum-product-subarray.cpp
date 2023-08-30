class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = 1, minSoFar = 1;
        int maxProductRes = nums[0];
        
        for(int num : nums) {
            int prevMax = maxSoFar;
            maxSoFar = max(maxSoFar * num, minSoFar * num);
            minSoFar = min(prevMax * num, minSoFar * num);
            
            maxProductRes = max(maxProductRes, maxSoFar);
            maxSoFar = max(maxSoFar, 1);
        }
        
        return maxProductRes;
    }
};