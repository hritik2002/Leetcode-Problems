class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int _max = nums[0], _min = nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = _max ;
            _max = max(nums[i],max(_max*nums[i],_min*nums[i]));
            _min = min(nums[i],min(_min*nums[i],temp*nums[i]));
            res = max(_max,res);
            if(_max<=0)_max = 1 ;
        }
        return res;
        
    }
};