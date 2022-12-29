class Solution {
public:
    vector<int> dp;
    int getMinimumTime(int node, vector<int> &children, map<int, vector<int>> &mp, vector<int> &time) {
        if(dp[node - 1] != -1) {
            return dp[node - 1];
        }
        int sum = 0;
        for(auto c : children) {
            sum = max(sum, getMinimumTime(c, mp[c], mp, time));
        }
        
        return dp[node - 1] = sum + time[node - 1];
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        map<int, vector<int>> mp;
        dp.resize(time.size(), -1);
        if(relations.size() == 0) {
            int sum = 0;
            for(auto t : time) 
                sum = max(sum, t);
            
            return sum;
        }
        
        for(int i = 1; i <= time.size(); i++) {
            mp[i] = {};
        }
        for(auto r : relations) {
            mp[r[1]].push_back(r[0]);
        }
        
        int sum = 0;
        for(int i = 1; i <= time.size(); i++) {
            sum = max(sum, getMinimumTime(i, mp[i], mp, time));
        }
        
        return sum;
    }
};