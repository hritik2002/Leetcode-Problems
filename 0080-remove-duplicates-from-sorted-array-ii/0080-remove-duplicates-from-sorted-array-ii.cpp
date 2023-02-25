class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1, n = nums.size(), j = 1;
        int cnt = 0;
        
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i - 1]) {
                if(cnt < 1) {
                    k++;
                    nums[j] = nums[i];
                    j++;
                    cnt++;
                }
            }else {
                cnt = 0;
                nums[j] = nums[i];
                k++;
                j++;
            }
            
        }
        
        return k;
    }
};