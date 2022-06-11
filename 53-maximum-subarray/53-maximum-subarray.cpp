class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int _maxSum = INT_MIN;
        int _maxAns = INT_MIN;
        for(int i=0 ; i<nums.size(); i++){
            _maxSum = nums[i] + max(_maxSum,0);
            _maxAns = max(_maxAns,_maxSum);
        }
        return _maxAns;
    }
};
