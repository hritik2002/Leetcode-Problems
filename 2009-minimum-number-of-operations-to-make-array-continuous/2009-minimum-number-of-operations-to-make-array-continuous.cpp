class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = n;
        // delete duplicates
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            while(j < nums.size() && nums[j] - nums[i] <= n - 1) {
                j++;
            }
            
            mini = min(mini, n - j + i);
        }
        
        return mini;
    }
};