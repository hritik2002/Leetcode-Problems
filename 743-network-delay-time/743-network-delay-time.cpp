class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<pair<int, int>> _queue;
        vector<pair<int, int>> adj[n + 1];
        vector<int> dist(n + 1, INT_MAX);
        
        for(auto time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        
        _queue.push({k, 0});
        int ans = 0;
        dist[k] = 0;
        
        while(!_queue.empty()) {
            int size = _queue.size();
            
            for(int i = 0; i < size; i++) {
                auto front = _queue.front();
                _queue.pop();
                
                for(auto node : adj[front.first]) {
                    if(dist[node.first] <= front.second + node.second) {
                        continue;
                    }
                    
                    dist[node.first] = min(dist[node.first], front.second + node.second);
                    _queue.push({node.first, front.second + node.second});
                }
                
            }
        }
        
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dist[i]);
            
            if(dist[i] == INT_MAX) {
                return -1;
            }
        }
        
        return ans;
    }
};