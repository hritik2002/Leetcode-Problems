class Solution {
public:
    int bfs(int n, vector<vector<pair<int, int>>>& edges, int src, int dst, int k) {
        queue<pair<int, int>> pq;
        vector<int> dist(n, INT_MAX);
        pq.push({0, src});
        dist[src] = 0;
        
        while(pq.size() && k > 0) {
            int size = pq.size();
            k--;
            
            while(size--) {
                auto top = pq.front();
                pq.pop();
                
                for(auto edge : edges[top.second]) {
                    if(dist[edge.first] > top.first + edge.second) {
                        dist[edge.first] = top.first + edge.second;
                        pq.push({top.first + edge.second, edge.first});
                    }
                }
            }
        }
        
        
        if(dist[dst] == INT_MAX) {
            return -1;
        }
        
        return dist[dst];
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> edges(n);
        for(auto flight : flights) {
            edges[flight[0]].push_back({flight[1], flight[2]});
        }
        
        return bfs(n, edges, src, dst, k + 1);
    }
};