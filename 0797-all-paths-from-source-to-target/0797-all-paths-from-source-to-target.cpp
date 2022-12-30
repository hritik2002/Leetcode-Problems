class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int node, int lastNode, vector<vector<int>> &graph, vector<int> &path) {
        path.push_back(node);
        
        if(node == lastNode) {
            ans.push_back(path);
        }
        for(auto child : graph[node]) {
            dfs(child, lastNode, graph, path);
        }
        
        path.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> path;
        dfs(0, nodes - 1, graph, path);
        
        return ans;
    }
};