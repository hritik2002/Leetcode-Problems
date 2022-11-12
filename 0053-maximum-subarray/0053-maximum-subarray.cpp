class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, ans = INT_MIN;
        
        for(auto n : nums) {
            curr = n + max(curr, 0);
            ans = max(ans, curr);
        }
        
        return ans;
    }
};