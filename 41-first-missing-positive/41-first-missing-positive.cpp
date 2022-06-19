class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int _min = INT_MAX;
        bool flag = true;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>0){
                if(i+1<=n &&nums[i]!=nums[i+1] && nums[i]!=nums[i+1]-1){
                    _min = min(_min,nums[i]+1);
                }
            }
            if(nums[i]==1)flag=false;
        }
        if(flag)return 1;
        if(_min<0)return 1;
        if(nums[0]>1)_min = min(_min,nums[0]-1);
        if(nums[n] <INT_MAX-1)
            _min = min(_min,nums[n]+1);
        return _min;
    }
};