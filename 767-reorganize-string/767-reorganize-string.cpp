class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> maxHeap;
        map<char, int> mp;
        int len = s.length();
        
        for(int i = 0; i < len; i++) {
            mp[s[i]]++;
        }
        
        for(auto x : mp) {
            maxHeap.push({x.second, x.first});
        }
        
        string ans = "";
        
        while(maxHeap.size() > 1) {
            auto top = maxHeap.top();
            maxHeap.pop();
            auto top2 = maxHeap.top();
            maxHeap.pop();
            
            if(top.first > 1) {
                maxHeap.push({top.first - 1, top.second});
            }
            if(top2.first > 1) {
                maxHeap.push({top2.first - 1, top2.second});
            }
            
            ans += top.second;
            ans += top2.second;
            
        }
        
        if(maxHeap.size()) {
            if(maxHeap.top().first > 1)
                return "";
            else ans += maxHeap.top().second;
        }
        
        return ans;
    }
};