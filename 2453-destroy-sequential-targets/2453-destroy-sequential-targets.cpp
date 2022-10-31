class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> mp;
        int ans = INT_MAX, mx = 0;
        // (nums[j] - nums[i]) % space = c;
        
        for(auto num : nums) {
            mx = max(mx, ++mp[num % space]);
        }
        for(auto num : nums) {
            if(mp[num % space] == mx) {
                ans = min(ans, num);
            }
        }
        
        return ans;
    }
};