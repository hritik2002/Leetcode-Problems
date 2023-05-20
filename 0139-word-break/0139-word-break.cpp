class Solution {
public:
    map<string, bool> dp;
    bool dfs(string sub, string s, int i, set<string> &st) {
        string key = sub + "-" + to_string(i);
        
        if(dp.count(key)) return dp[key]; 
        if(i == s.length()) {
            return st.count(sub);
        }
        
        string tmp = "";
        tmp += s[i];
        
        if(st.count(sub) && dfs(tmp, s, i + 1, st)) {
            return dp[key] = true;
        }
        
        return dp[key] = dfs(sub + s[i], s, i + 1, st);
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        
        for(auto str : wordDict)
            st.insert(str);
        
        return dfs("", s, 0, st);
    }
};