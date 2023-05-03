class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        int n = nums.size();
        long long ans = n;
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < n; i++) {
            if(mp[nums[i - 1]] > mp[nums[i]]) {
                ans += n - i;
            }
        }
        
        return ans;
    }
};