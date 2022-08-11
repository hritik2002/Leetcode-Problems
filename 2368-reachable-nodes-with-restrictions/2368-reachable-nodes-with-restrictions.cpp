class Solution {
public:
    
    int count = 0;
    
    void dfs(vector<bool> &visited, vector<int> adj[], int curr) {
        
        count++;
        visited[curr] = true;
        
        for(auto node : adj[curr]) {
            if(visited[node]) {
                continue;
            }
            dfs(visited, adj, node);
        }
        
        return;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<int> adj[n];
        vector<bool> visited(n, false);
        
        for(auto num : restricted) {
            visited[num] = true;
        }
        
        for(int i = 0; i < n - 1; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        dfs(visited, adj, 0);
        
        return count;
    }
};