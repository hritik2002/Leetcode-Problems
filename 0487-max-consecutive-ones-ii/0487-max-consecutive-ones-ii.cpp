class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int k = 1;
        int i = 0, j = 0, n = nums.size();
        int ans = 0;
        
        while(i < n) {
            while(i < n && (k || nums[i] == 1)) {
                if(nums[i] != 1) {
                    k--;
                }
                
                i++;
            }
            
            if(j >= n) {
                break;
            }
            
            ans = max(ans, i - j);
            if(nums[j] != 1) {
                k++;
            }
            
            j++;
        }
        
        return ans;
    }
};