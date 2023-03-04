class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int right = 0, ans = 0;
        int n = nums.size();
        int numOfOdds = 0;
        unordered_map<int, int> mp;
        
        for(; right < n; right++) {
            if(nums[right] % 2) {
                numOfOdds++;
            }
            if(numOfOdds == k) {
                ans++;
            }
            if(mp[numOfOdds - k]) {
                ans += mp[numOfOdds - k];
            }
            
            mp[numOfOdds]++;
        }
        
        return ans;
    }
};