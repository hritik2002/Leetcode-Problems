class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        nums.resize(std::distance(nums.begin(), unique(nums.begin(), nums.end())));
        
        if(nums.size() == 2)return nums[1];
        else if(nums.size() == 1)return nums[0];
        
        return nums[nums.size() - 3];
    }
};