class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int AND = 0;
        
        for(int i = 0, j = 0; i < n; i++) {
            while((AND & nums[i]) > 0) {
                AND ^= nums[j++];
            }
            
            AND |= nums[i];
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};