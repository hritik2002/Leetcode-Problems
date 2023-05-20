class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int mod = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int m = nums[0], res = (1LL * ((1LL * m * m) % mod) * m % mod) % mod;
        int n = nums.size();
        
        
        for(int i = 1; i < n; i++) {
            m = m * 2 % mod - nums[i - 1] + nums[i];
            res = (res + ((((1LL * nums[i] * nums[i]) % mod) * m % mod)) % mod) % mod;
        }
        
        return res;
    }
};