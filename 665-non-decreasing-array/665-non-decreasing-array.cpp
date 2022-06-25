class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                int j = i-1;
                if(i==1 || (i-1>0 && nums[i-2]<=nums[i])){
                    nums[i-1] = nums[i];
                }else {
                    nums[i] = nums[i-1];
                }
                break;
            }
        }
        for(int i=1;i<n;i++)if(nums[i-1]>nums[i])return false;
        return true;
    }
};