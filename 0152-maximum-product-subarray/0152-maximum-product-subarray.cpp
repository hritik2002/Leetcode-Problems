class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], _max = 1, _min = 1;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            int tmp = _max;
            _max = max(_max * nums[i], _min * nums[i]);
            _min = min(_min * nums[i], tmp * nums[i]);
            res = max(_max, res);
            _max = max(_max, 1);
        }
        
        return res;
    }
};