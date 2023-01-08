class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) {
            if(k & 1) {
                return -1;
            }
            
            return nums[0];
        }
        if(k <= 1) {
            return nums[k];
        }
        if(k < n) {
            return max(nums[k], *max_element(nums.begin(), nums.begin() + k - 1));
        }
        if(k==n){
            return *(max_element(nums.begin(),nums.begin() + k-1));
        }
        
        return *(max_element(nums.begin(),nums.begin()+n));
    }
};