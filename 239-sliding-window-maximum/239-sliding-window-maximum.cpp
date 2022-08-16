class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq;
        vector<int> ans;
        map<int, int> mp;
        int n = nums.size();
        
        for(int i = 0; i < k; i++) {
            pq.push(nums[i]);
            mp[nums[i]]++;
        }
        
        int i = 0;
        
        for(int j = k; j < n; j++, i++) {
            while(!mp[pq.top()]) {
                pq.pop();
            }
            ans.push_back(pq.top());
            
            if(pq.top() == nums[i]) {
                pq.pop();
            }
            
            pq.push(nums[j]);
            mp[nums[j]]++;
            mp[nums[i]]--;
        }
        
        while(!mp[pq.top()]) {
                pq.pop();
        }
        ans.push_back(pq.top());
        
        return ans;
    }
    
};