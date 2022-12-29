class Solution {
public:
    int minJumps(vector<int>& arr) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});    // distance, index
        vector<bool> visited(arr.size(), false);
        map<int, vector<int>> mp;
        
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]].push_back(i);
        }
        
        while(pq.size()) {
            pair<int, int> top = pq.top();
            pq.pop();
            
            if(top.second == arr.size() - 1) {
                return top.first;
            }
            if(visited[top.second]) {
                continue;
            }
            
            if(top.second - 1 >= 0 && visited[top.second - 1] == false) {
                pq.push({top.first + 1, top.second - 1});
                visited[top.second] = true;
            }
            if(top.second + 1 < arr.size() && visited[top.second + 1] == false) {
                pq.push({top.first + 1, top.second + 1});
                visited[top.second] = true;
            }
            vector<int> v = mp[arr[top.second]];
            for(int i = 0; i < v.size(); i++) {
                if(top.second != v[i] && visited[v[i]] == false) {
                    pq.push({top.first + 1, v[i]});
                    visited[top.second] = true;
                }
            }
            mp.erase(arr[top.second]);
        }
        
        return -1;
    }
};