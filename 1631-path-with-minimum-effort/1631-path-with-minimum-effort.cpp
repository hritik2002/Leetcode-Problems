class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>> visited(n, vector<int> (m, false));
        int ans = 0;
        
        pq.push({0, {0, 0}});
        visited[0][0] = true;
        
        while(pq.size()) {
            auto top = pq.top();
            int indexI = top.second.first, indexJ = top.second.second;
            
            pq.pop();
            
            ans = max(ans, top.first);
            visited[indexI][indexJ] = true;

            if(indexI == n - 1 && indexJ == m - 1) {
                return ans;
            }
            
            // move down
            if(indexI + 1 < n && visited[indexI + 1][indexJ] == false) {
                int diff = abs(heights[indexI][indexJ] - heights[indexI + 1][indexJ]);
                pq.push({diff, {indexI + 1, indexJ}});
            }
            
            // move up
            if(indexI - 1 >= 0 && visited[indexI - 1][indexJ] == false) {
                int diff = abs(heights[indexI][indexJ] - heights[indexI - 1][indexJ]);
                pq.push({diff, {indexI - 1, indexJ}});
            }
            
            // move right
            if(indexJ + 1 < m && visited[indexI][indexJ + 1] == false) {
                int diff = abs(heights[indexI][indexJ] - heights[indexI][indexJ + 1]);
                pq.push({diff, {indexI, indexJ + 1}});
            }
            
            // move left
            if(indexJ - 1 >= 0 && visited[indexI][indexJ - 1] == false) {
                int diff = abs(heights[indexI][indexJ] - heights[indexI][indexJ - 1]);
                pq.push({diff, {indexI, indexJ - 1}});
            }
        }
        
        return ans;
    }
};