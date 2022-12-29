class Solution {
public:
    set<int> visited;
    vector<int> dp;
    int getMinimumSem(int node, vector<vector<int>> &nodes) {
        if(visited.count(node)) {
            return -1;
        }
        if(dp[node] != -1) {
            return dp[node];
        }
        
        visited.insert(node);
        int minSem = 0;
        for(auto child : nodes[node]) {
            int ans = getMinimumSem(child, nodes);
            if(ans == -1) {
                return -1;
            }
            
            minSem = max(minSem, ans);
        }
        visited.erase(node);
        
        return dp[node] = minSem + 1;
    }
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        int minSem = 0;
        vector<vector<int>> nodes(n + 1);
        dp.resize(n + 1, -1);
        
        for(auto relation : relations) {
            nodes[relation[1]].push_back(relation[0]);
        }
        
        for(int i = 1; i <= n; i++) {
            int ans = getMinimumSem(i, nodes);
            if(ans == -1) {
                return -1;
            }
            
            minSem = max(minSem, ans);
        }
        
        return minSem;
    }
};