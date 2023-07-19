class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int i = 0, j, n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(j = 0; j < n; j++) {
            if(nums[j] - nums[i] > k * 2) {
                i++;
            }
        }
        
        return j - i;
    }
};

// 1 2 4 6
