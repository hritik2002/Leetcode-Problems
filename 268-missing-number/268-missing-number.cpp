class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int left = 0, right = n - 1;
        int target = 0;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
                target++;
                left = mid;
                right = n - 1;
            }else if(nums[mid] < target) {
                left = mid + 1;
            }else right = mid - 1;
        }
        
        return target;
    }
};