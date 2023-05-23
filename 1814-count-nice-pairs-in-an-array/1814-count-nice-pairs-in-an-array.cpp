class Solution {
public:
    int rev(int n) {
        int reverse = 0;
        
        while(n) {
            reverse = reverse * 10 + n % 10;
            n = n / 10;
        }
        
        return reverse;
    }
    int countNicePairs(vector<int>& nums) {
        map<long long, long long> mp;
        int mod = 1e9 + 7;
        long long ans = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            long long key = nums[i] - rev(nums[i]);
            mp[key]++;
        }
        
        for(auto _map : mp) {
            int key = _map.first, value = _map.second;
            value--;
            
            ans +=  ((long long) value * (value + 1) / 2) % mod;
            ans %= mod;
        }
        
        return ans;
    }
};