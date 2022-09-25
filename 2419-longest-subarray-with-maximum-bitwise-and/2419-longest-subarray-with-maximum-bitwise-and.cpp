class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int n = nums.size(), res = 1, len = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == maxNum) {
                len++;
            }else len = 0;
            
            res = max(res, len);
        }
        
        return res;
    }
};