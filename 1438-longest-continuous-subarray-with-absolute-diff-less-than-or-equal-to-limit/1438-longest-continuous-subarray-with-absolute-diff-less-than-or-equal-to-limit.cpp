class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        deque<int> maxD;
        deque<int> minD;
        int i = 0, j = 0;
        int n = nums.size();
        
        for(; i < n; i++) {
            while(maxD.size() && maxD.back() < nums[i]) {
                maxD.pop_back();
            }
            while(minD.size() && minD.back() > nums[i]) {
                minD.pop_back();
            }
            
            maxD.push_back(nums[i]);
            minD.push_back(nums[i]);
            if((maxD.front() - minD.front()) > limit) {
                if(maxD.front() == nums[j]) maxD.pop_front();
                if(minD.front() == nums[j]) minD.pop_front();
                j++;
            }
            
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};