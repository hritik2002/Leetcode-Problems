class Solution {
public:
    int dfs(vector<vector<int>>& connList, int node, int parent, vector<bool>& hasApple) {
        int res = 0;
        
        for(auto child : connList[node]) {
            if(child == parent) continue;
            
            res += dfs(connList, child, node, hasApple);
        }
        
        if(res > 0 || hasApple[node]) {
            res += 2;
        }
        
        return res;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> connList(n);
        
        for(auto edge : edges) {
            connList[edge[0]].push_back(edge[1]);
            connList[edge[1]].push_back(edge[0]);
        }
        
        int ans = dfs(connList, 0, -1, hasApple) - 2;
        
        return ans < 0 ? 0 : ans;
    }
};