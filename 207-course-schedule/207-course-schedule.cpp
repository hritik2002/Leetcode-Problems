class Solution {
public:
    vector<bool> dfsVisited;
    bool checkCycle(vector<int> adj[], int node, vector<bool> &visited) {
        visited[node] = true;
        dfsVisited[node] = true;
        
        for(auto neighbor : adj[node]) {
            if(visited[neighbor] && dfsVisited[neighbor]) {
                return true;
            }
            if(visited[neighbor]) {
                continue;
            }
            
            if(checkCycle(adj, neighbor, visited)) {
                return true;
            }
        }
        
        dfsVisited[node] = false;
        
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        dfsVisited.resize(numCourses, false);
        
        for(auto arr : prerequisites) {
            adj[arr[1]].push_back(arr[0]);
        }
        
        vector<bool> visited(numCourses, false);
        
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == false && checkCycle(adj, i, visited)) {
                return false;
            }
        }
        
        return true;
    }
};