class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int n = nums.size();
        int _max = nums[0], _min = nums[0];
        
        for(int i = 0; i < n; i++) {
            _max = max(_max, nums[i]);
            _min = min(_min, nums[i]);
            
            if(_max - _min > k) {
                cnt++;
                _max = nums[i];
                _min = nums[i];
            }
        }
        
        return cnt;
    }
};

// 1 2 3 5 6

// 1 2 3
// 5 6


// 1 2 3
// 1 2
// 3


// 2 2 4 5
// 2 2
// 4
// 5