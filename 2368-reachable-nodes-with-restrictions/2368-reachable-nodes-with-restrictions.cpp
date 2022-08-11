class Solution {
public:
    void dfs(int u, vector<int> adj[], int &cnt, vector<bool> &vis)
    {
        vis[u] = true;
        // if we reach a new node, while performing dfs, we increase our count by 1
        cnt++; 
        for (auto v : adj[u])
        {
            if (vis[v] == false)
            {
                dfs(v, adj, cnt, vis);
            }
        }
    }
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted)
    {
        vector<bool> visited(n, false);
        vector<int> adj[n]; // adjency list
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for (auto a : restricted)
        {
            visited[a] = true; // marking the restricted nodes  as visited.
        }
        int count = 0;
        dfs(0, adj, count, visited);
        return count;
    }
};