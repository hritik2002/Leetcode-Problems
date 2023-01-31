class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int n = nums.size();
        int ans = 0;
        
        while(i < n) {
            while(i < n && (k || nums[i] == 1)) {
                if(nums[i] != 1) {
                    k--;
                }
                
                i++;
            }
            
            ans = max(ans, i - j);
            if(j >= n) break;
            if(nums[j] != 1) {
                k++;
            }
            
            j++;
        }
        
        return ans;
    }
};