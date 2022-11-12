class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long cnt = 0, i = 0, sum = 0;
        
        for(int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            
            while(sum*(j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }
            cnt += j - i + 1;
        }
        
        return cnt;
    }
};