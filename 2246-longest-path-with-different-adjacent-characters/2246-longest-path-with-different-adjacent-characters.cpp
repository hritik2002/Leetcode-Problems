class Solution {
public:
    int ans = 0;
    int dfs(vector<vector<int>>& connList, string& s, int node, int parent) {
        int res = 0;
        int _max = 0;
        int big1 = 0, big2 = 0;
        
        for(auto child : connList[node]) {
            if(child == parent) continue;
        
            int rec = dfs(connList, s, child, node);
            
            if(rec > big2) big2 = rec;
            if(big2 > big1) swap(big1, big2);
            
        }
        
        ans = max(ans, big1 + big2 + 1);
        if(parent == -1) {
            return big1 + 1;
        }
        if(s[parent] == s[node]) {
            return 0;
        }

        return big1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> connList(n);
        
        for(int i = 0; i < n; i++) {
            if(parent[i] == -1) continue;
            
            connList[parent[i]].push_back(i);
            connList[i].push_back(parent[i]);
        }
        
        dfs(connList, s, 0, -1);
        
        return ans;
    }
};