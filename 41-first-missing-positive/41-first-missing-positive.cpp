class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int _max = 1;
        for(int i=0;i<n;){
            if(nums[i]>0 && nums[i]<=n){
                _max = max(_max,nums[i]);
                while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
                    int temp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = temp ;
                }
            } 
            i++;
        }
        for(int i=0;i<n;i++)cout<<nums[i]<<" ";
        for(int i=0;i<n;i++){
            if( i+1!=nums[i])return i+1;
        }
        return _max+1;
    }
};