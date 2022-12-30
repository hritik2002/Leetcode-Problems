class Solution {
public:
    vector<int> ans;
    vector<bool> visited;
    int dfs(int node, map<int, vector<int>> &mp, set<int> &detectCycle) {
        if(detectCycle.count(node)) {
            return -1;
        }
        if(visited[node]) {
            return 0;
        }
        
        
        detectCycle.insert(node);
        visited[node] = true;
        for(auto child : mp[node]) {
            int res = dfs(child, mp, detectCycle);
            
            if(res == -1) {
                return -1;
            }
        }
        ans.push_back(node);
        detectCycle.erase(node);
        
        return 0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> mp;
        visited.resize(numCourses, false);
        
        for(int i = 0; i < numCourses; i++) {
            mp[i] = {};
        }
        for(auto p : prerequisites) {
            mp[p[0]].push_back(p[1]);
        }
        for(int i = 0; i < numCourses; i++) {
            set<int> detectCycle;
            int res = dfs(i, mp, detectCycle);
            
            if(res == -1) {
                return {};
            }
        }
        
        return ans;
    }
};