class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int i = 0, j = 0;
        int n = nums.size();
        
        for(; i < n; i++) {
            maxHeap.push({nums[i], i});
            minHeap.push({nums[i], i});
            
            while(maxHeap.size() && maxHeap.top().second < j) {
                maxHeap.pop();
            }
            while(minHeap.size() && minHeap.top().second < j) {
                minHeap.pop();
            }
            if(maxHeap.top().first - minHeap.top().first > limit) {
                j++;
            }
            
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};