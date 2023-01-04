class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        int ans = 0;
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int> (n, false));
        visited[0][0] = true;
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int x = top.second.first, y = top.second.second;
            int value = top.first;
            ans = max(ans, value);
            if(x == n - 1 && y == n - 1) {
                return ans;
            }
            
            // down
            if(x + 1 < n && !visited[x + 1][y]) {
                pq.push({grid[x + 1][y], {x + 1, y}});
                visited[x + 1][y] = true;
            }
            // up
            if(x - 1 >= 0 && !visited[x - 1][y]) {
                pq.push({grid[x - 1][y], {x - 1, y}});
                visited[x - 1][y] = true;
            }
            // right
            if(y + 1 < n && !visited[x][y + 1]) {
                pq.push({grid[x][y + 1], {x, y + 1}});
                visited[x][y + 1] = true;
            }
            // left
            if(y - 1 >= 0 && !visited[x][y - 1]) {
                pq.push({grid[x][y - 1], {x, y - 1}});
                visited[x][y - 1] = true;
            }
        }
        
        return ans;
    }
};