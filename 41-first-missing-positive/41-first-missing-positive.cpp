class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;){
            if(nums[i]>0 && nums[i]<=n){
                while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                    int temp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = temp ;
                }
            } 
            i++;
        }
        for(int i=0;i<n;i++){
            if( i+1!=nums[i])return i+1;
        }
        return n+1;
    }
};