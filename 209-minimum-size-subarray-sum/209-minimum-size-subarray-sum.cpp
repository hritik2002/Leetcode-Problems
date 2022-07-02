class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, length = INT_MAX, n = nums.size() ;
        while(right<n){
            sum += nums[right];
            right++;
            while(sum>=target){
                length = min(length,right-left);
                sum -= nums[left];
                left++;
            }
        }
        if(length<INT_MAX)return length;
        return 0;
    }
};