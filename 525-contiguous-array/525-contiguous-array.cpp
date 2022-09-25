class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> mp;
        mp[0] = -1;
        int ans = 0, sum = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            sum += nums[i] == 1 ? 1 : -1;
            
            if(mp.count(sum)) {
                ans = max(ans, i - mp[sum]);
            }else mp[sum] = i;
        }
        
        return ans;
    }
};