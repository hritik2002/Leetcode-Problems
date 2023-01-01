class Solution {
public:
    int mod = 1e9 + 7;
    long long dijkstra(int src, vector<vector<pair<int, int>>> &adj, int n) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});    // source and time
        vector<long long> ways(n);
        vector<long long> dist(n, LONG_MAX);
        ways[src] = 1;
        dist[src] = 0;
        
        while(!pq.empty()) {
            auto top = pq.top();
            int u = top.second;
            pq.pop();
            
            if(dist[u] < top.first) {
                continue;
            }
            
            for(auto child : adj[u]) {
                long long time = child.second;
                int v = child.first;
                
                if(dist[v] > (time + top.first)) {
                    dist[v] = (time + top.first);
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }else if(dist[v] == (time + top.first)) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
                
            }
        }
        
        return ways[n - 1];
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjacency_list(n);
        vector<bool> visited(n, false);
        
        for(auto road : roads) {
            adjacency_list[road[0]].push_back({road[1], road[2]});
            adjacency_list[road[1]].push_back({road[0], road[2]});
        }
        
        return dijkstra(0, adjacency_list, n);
    }
};