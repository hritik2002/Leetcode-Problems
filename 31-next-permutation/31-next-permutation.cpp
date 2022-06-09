class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = 0,i ;
        bool flag = false;
        for( i=nums.size()-1 ; i>=1;i--){
            if(nums[i]>nums[i-1]){
                index = i-1;
                flag = true;
                break;
                
            }
        }
        if(!flag){ reverse(nums.begin(),nums.end());return;}
        for(int i=nums.size()-1 ; i>=1;i--){
            if(nums[i]>nums[index]){
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
                break;
            }
        }
        reverse(nums.begin()+1+index,nums.end());
        return ;
    }
};