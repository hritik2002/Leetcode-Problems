class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        int p = 1;
        p = p << k;
        
        vector<int> pref(n + 1, 0), suff(n + 1, 0);
        
        for(int i = 1; i <= n; i++) 
            pref[i] = pref[i - 1] | nums[i - 1];
        for(int i = n - 1; i >= 0; i--) 
            suff[i] = suff[i + 1] | nums[i];
        
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            ans = max(ans,(long long) nums[i] * p | pref[i] | suff[i + 1]);
        }
        
        return ans;
    }
};