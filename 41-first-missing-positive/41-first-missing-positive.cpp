class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int _min = INT_MAX;
        set<int>st;
        int n  = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>n)continue;
            if(nums[i]>0){
                st.insert(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                if((!st.count(nums[i]-1) && nums[i]>1)){
                    _min = min(_min,nums[i]-1);
                }else if(!st.count(nums[i]+1)){
                    _min = min(_min,nums[i]+1);
                }
            }
        }
        if(!st.count(1))return 1;
        return _min;
    }
};