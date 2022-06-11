class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN , _max = INT_MIN;
        for(int i=0 ; i<nums.size() ; i++){
            sum = nums[i] + max(sum,0);
            _max = max(sum,_max);
        }
        return _max;
        
        
    }
};