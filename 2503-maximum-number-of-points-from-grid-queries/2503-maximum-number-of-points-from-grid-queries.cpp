class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> ans(queries.size());
        int cnt = 0;
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;
        
        for(auto query : q) {
            
            while(!pq.empty() && pq.top().first < query.first) {
                auto top = pq.top();
                pq.pop();
                int x = top.second.first, y = top.second.second;
                int value = top.first;
                
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
                // left
                if(y - 1 >= 0 && !visited[x][y - 1]) {
                    pq.push({grid[x][y - 1], {x, y - 1}});
                    visited[x][y - 1] = true;
                }
                // right
                if(y + 1 < m && !visited[x][y + 1]) {
                    pq.push({grid[x][y + 1], {x, y + 1}});
                    visited[x][y + 1] = true;
                }
                
                cnt++;
            }
            
            ans[query.second] = cnt;
        }
        
        return ans;
    }
};