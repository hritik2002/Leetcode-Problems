class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            ans |= nums[i];
        }
        
        return ans;
    }
};