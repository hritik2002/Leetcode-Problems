class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>arr(nums.size());
        int _maxSum = INT_MIN;
        int _maxAns = INT_MIN;
        for(int i=0 ; i<nums.size(); i++){
            arr[i] = nums[i] + max(_maxSum,0);
            _maxSum = arr[i];
            _maxAns = max(_maxAns,_maxSum);
        }
        return _maxAns;
        
    }
};
