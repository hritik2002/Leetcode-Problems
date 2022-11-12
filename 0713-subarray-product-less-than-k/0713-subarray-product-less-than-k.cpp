class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1, i = 0, cnt = 0;
        
        for(int j = 0; j < nums.size(); j++) {
            prod *= nums[j];
            
            while(i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            
            cnt += (j - i + 1);
        }
        
        return cnt;
    }
};