class Solution {
public:
    set<int> ans;
    void killProcessHelper(vector<vector<int>>& conn, int parent) {
        ans.insert(parent);
        
        for(auto child : conn[parent]) {
            if(!ans.count(child))
                killProcessHelper(conn, child);
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<vector<int>> conn(5e4 + 2);
        int size = pid.size();
        
        for(int i = 0; i < size; i++) {
            conn[ppid[i]].push_back(pid[i]);
        }
        killProcessHelper(conn, kill);
        vector<int> result;
        
        for(auto node : ans) {
            result.push_back(node);
        }
        
        return result;
    }
};