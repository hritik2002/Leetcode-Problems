class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = count(nums.begin(), nums.end(), 1);
        int n = nums.size();
        
        if(cnt > 0) {
            return (n - cnt);
        }
        int res = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            int g = nums[i];
            for(int j = i + 1; j < n; j++) {
                g = __gcd(g, nums[j]);
                
                if(g == 1) {
                    res = min(res, j - i + (n - 1));
                    break;
                }
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};