class Solution {
public:
    int ans = 0;
    int dfs(vector<vector<int>>& edges, int node, int parent) {
        int child1 = 0, child2 = 0;
        
        for(auto child : edges[node]) {
            if(child == parent) continue;
            
            int res = dfs(edges, child, node);
            
            if(res >= child1) {
                child2 = child1;
                child1 = res;
            }else if(res > child2) {
                child2 = res;
            }
        }
        
        ans = max(ans, child1 + child2 + 1);
        
        return max(child1, child2) + 1;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        vector<vector<int>> connections(edges.size() + 1);
        for(auto edge : edges) {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }
        
        dfs(connections, 0, -1);
        
        return ans - 1;
    }
};