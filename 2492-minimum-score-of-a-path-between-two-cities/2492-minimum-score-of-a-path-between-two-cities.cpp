class Solution {
public:
    int ans = INT_MAX;
    set<int> st;
    
    void dfs(vector<vector<pair<int, int>>> &grid, int node, int n) {
        st.insert(node);
        
        for(auto child : grid[node]) {
            ans = min(ans, child.second);
            
            if(!st.count(child.first)) {
                dfs(grid, child.first, n);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> grid(n + 1);
        
        for(auto road : roads) {
            grid[road[0]].push_back({road[1], road[2]});
            grid[road[1]].push_back({road[0], road[2]});
        }
        
        dfs(grid, 1, n);
        
        return ans;
    }
};