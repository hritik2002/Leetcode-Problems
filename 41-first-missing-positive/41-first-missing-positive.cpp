class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>st;
        int n = nums.size()-1;
        int _min = INT_MAX;
        for(int i=0; i<nums.size();i++){
            if(nums[i]>0){
                if(i+1<=n &&nums[i]!=nums[i+1] && nums[i]!=nums[i+1]-1){
                    _min = min(_min,nums[i]+1);
                }
            }
            st.insert(nums[i]);
        }
        if(!st.count(1))return 1;
        if(_min<0)return 1;
        if(nums[0]>1)_min = min(_min,nums[0]-1);
        if(nums[n] <INT_MAX-1)
            _min = min(_min,nums[n]+1);
        return _min;
    }
};