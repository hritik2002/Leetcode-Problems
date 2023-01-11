class Solution {
public:
    
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        map<char, set<char>> mp;
        
        for(auto map : mappings) {
            mp[map[0]].insert(map[1]);
        }
        
        for(int i = 0; i + sub.length() <= s.length(); i++) {
            int j;
            
            for(j = 0; j < sub.length(); j++) {
                if(s[i + j] != sub[j] && mp[sub[j]].count(s[i + j]) == 0) {
                    break;
                }
            }
            
            if(j == sub.length()) {
                return true;
            }
        }
        
        return false;
    }
};