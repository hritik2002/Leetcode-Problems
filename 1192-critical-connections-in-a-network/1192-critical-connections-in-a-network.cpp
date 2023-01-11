class Solution {
public:
    vector<int> rank;
    
    void removeConn(vector<set<int>>& connList, int node, int child) {
        connList[node].erase(child);
        connList[child].erase(node);
        
        return;
    }
    int dfs(vector<set<int>>& connList, int node, int discoveryRank, int parent) {
        if(rank[node] != INT_MAX) {
            return rank[node];
        }
        
        rank[node] = discoveryRank;
        int minRank = INT_MAX;
        for(auto child : connList[node]) {
            if(parent == child) {
                continue;
            }
            
            int recRank = dfs(connList, child, discoveryRank + 1, node);
            minRank = min(minRank, recRank);
            
            if(recRank <= discoveryRank) {
                removeConn(connList, node, child);
            }
        }
        
        return minRank;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<set<int>> connList(n);
        rank.resize(n, INT_MAX);
        
        
        for(auto conn : connections) {
            connList[conn[0]].insert(conn[1]);
            connList[conn[1]].insert(conn[0]);
        }
        
        dfs(connList, 0, 0, -1);
        vector<vector<int>> ans;
        set<string> visited;
        
        for(int i = 0; i < n; i++) { 
            for(auto child : connList[i]) {
                if(visited.count(to_string(i) + "_" + to_string(child)) || visited.count(to_string(child) + "_" + to_string(i))) {
                    continue;
                }

                visited.insert(to_string(i) + "_" + to_string(child));
                ans.push_back({i, child});
            }
            
        }
        
        return ans;
    }
};