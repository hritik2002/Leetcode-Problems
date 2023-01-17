class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        long long ans = 0;
        long long n = nums.size();
        long long prefSum = 0;
        unordered_map<long long, long long> mp;
        
        for(long long i = 0; i < n; i++) {
            prefSum += nums[i];
            
            if(prefSum == k) ans = i + 1;
            else if(mp.count(prefSum - k)) {
                ans = max(ans, i - mp[prefSum - k]);
            }
            
            if(!mp.count(prefSum))
                mp[prefSum] = i;
        }
        
        return ans;
    }
};