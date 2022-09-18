class Solution {
public:
    // Bellmon ford
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while(k >= 0) {
            k--;
            vector<int> temp(dist);
            for(auto edge : flights) {
                if(dist[edge[0]] != INT_MAX) {
                    temp[edge[1]] = min(temp[edge[1]], edge[2] + dist[edge[0]]);
                }
            }
            dist = temp;
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};