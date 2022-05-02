class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0 , j = nums.size()-1 ;
        while(i<j){
            while(i<j && nums[i]%2==0)i++;
            while(i<j && nums[j]%2!=0)j--;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp ;
        }
        return nums;
    }
};