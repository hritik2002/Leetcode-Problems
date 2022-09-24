class Solution {
public:
    vector<int> ans;
    vector<bool> visited;
    vector<int> findCountSubTrees(int n, vector<vector<int>> &adj, string &labels, int node) {
        vector<int> cnt(26, 0);
        if(node == n) {
            return cnt;
        }
        visited[node] = true;
        
        cnt[labels[node] - 'a']++;
        
        for(auto neighbor : adj[node]) {
            if(visited[neighbor]) {
                continue;
            }
            vector<int> temp(26, 0);
            temp = findCountSubTrees(n, adj, labels, neighbor);
            
            for(int i = 0; i < 26; i++) {
                cnt[i] += temp[i];
            }
        }
        
        ans[node] = cnt[labels[node] - 'a'];
        
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n, 0);
        vector<vector<int>> adj(n);
        visited.resize(n, false);
        
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        findCountSubTrees(n, adj, labels, 0);
        
        return ans;
    }
};