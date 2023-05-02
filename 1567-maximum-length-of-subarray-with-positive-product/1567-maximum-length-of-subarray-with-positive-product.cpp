class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int frameStart = 0, firstNegative = -1;
        int n = nums.size();
        int len = 0;
        int neg = 0;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                frameStart = i + 1, firstNegative = -1;
                neg = 0;
            }else {
                if(nums[i] < 0) {
                    neg++;
                }
                
                if(neg == 1 && firstNegative == -1) {
                    firstNegative = i;
                }
                if(neg % 2 == 0) {
                    len = max(len, i - frameStart + 1);
                }else {
                    len = max(len, i - firstNegative);
                }
            }
        }
        
        return len;
    }
};