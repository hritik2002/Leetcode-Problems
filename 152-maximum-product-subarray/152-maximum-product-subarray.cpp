class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int _max = 1, _min = 1;
        for(int i=0;i<nums.size();i++){
            int temp = _max ;
            _max = max(_max*nums[i],_min*nums[i]);
            _min = min(_min*nums[i],temp*nums[i]);
            res = max(_max,res);
            if(_max<=0)_max = 1 ;
        }
        return res;
        
    }
};