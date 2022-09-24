class Solution {
public:
    void findValueOfEqn(string start, string end, double &val, bool &found, set<string> &visited, map<string, vector<string>> &graph, map<string, double> &weight) {
        visited.insert(start);
        
        if(start == end) {
            found = true;
            return;
        }
        
        for(auto node : graph[start]) {
            if(visited.count(node)) {
                continue;
            }
            
            val *= weight[start + "->" + node];
            findValueOfEqn(node, end, val, found, visited, graph, weight);
            
            if(found == true) {
                return;
            }
            
            val /= 1.0*weight[start + "->" + node];
        }
        
        return;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<string>> graph;
        map<string, double> weight;
        vector<double> ans;
        
        int i = 0;
        for(auto eqn : equations) {
            weight[eqn[0] + "->" + eqn[1]] = values[i];
            weight[eqn[1] + "->" + eqn[0]] = 1.0 / values[i];
            graph[eqn[0]].push_back(eqn[1]);
            graph[eqn[1]].push_back(eqn[0]);
            i++;
        }
        
        for(auto query : queries) {
            string start = query[0], end = query[1];
            
            if(graph.count(start) && graph.count(end)) {
                bool found = false;
                double val = 1.0;
                set<string> visited;
                
                
                if(start == end) {
                    found = true;
                }else findValueOfEqn(start, end, val, found, visited, graph, weight);
                
                if(found == true) {
                    ans.push_back(val);
                }else ans.push_back(-1);
                
            }else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};