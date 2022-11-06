class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<bool> pref(nums.size(), false), suff(nums.size(), false);
        int _max = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            if(_max < nums[i]) {
                pref[i] = true;
                _max = nums[i];
            }
        }
        
        int _min = nums[nums.size() - 1];
        suff[nums.size() - 1] = true;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < _min) {
                suff[i] = true;
                _min = nums[i];
            }
        }
        int sum = 0;
        
        for(int i = 1; i <= nums.size() - 2; i++) {
            if(pref[i] && suff[i]) {
                sum += 2;
            }else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                sum++;
            }
        }
        
        return sum;
    }
};