class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> pq;
        
        vector<vector<int>> dist(grid.size(), vector<int> (grid[0].size(), INT_MAX));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    pq.push({0, {i, j}});
                    dist[i][j] = 0;
                }
            }
        }
        
        int ans = 0;
        while(!pq.empty()) {
            int size = pq.size();
            
            while(size--) {
                auto top = pq.front();
                pq.pop();
                int x = top.second.first, y = top.second.second;
                int distance = top.first;
                
                if(x + 1 < n && grid[x + 1][y] == 0 && dist[x + 1][y] == INT_MAX) {
                    pq.push({distance + 1, {x + 1, y}});
                    dist[x + 1][y] = distance + 1;
                    ans = max(ans, distance + 1);
                }
                if(y + 1 < m && grid[x][y + 1] == 0 && dist[x][y + 1] == INT_MAX) {
                    pq.push({distance + 1, {x, y + 1}});
                    dist[x][y + 1] = distance + 1;
                    ans = max(ans, distance + 1);
                }
                if(x - 1 >= 0 && grid[x - 1][y] == 0 && dist[x - 1][y] == INT_MAX) {
                    pq.push({distance + 1, {x - 1, y}});
                    dist[x - 1][y] = distance + 1;
                    ans = max(ans, distance + 1);
                }
                if(y - 1 >= 0 && grid[x][y - 1] == 0 && dist[x][y - 1] == INT_MAX) {
                    pq.push({distance + 1, {x, y - 1}});
                    dist[x][y - 1] = distance + 1;
                    ans = max(ans, distance + 1);
                }
            }
        }
        
        return ans == 0 ? -1 : ans;
    }
};