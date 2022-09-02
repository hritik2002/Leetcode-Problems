class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        
        for(auto x : mp) {
            pq.push({x.second, x.first});
        }
    
        vector<int> ans;
        
        while(k-- && pq.size()) {
            auto top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        
        return ans;
    }
};