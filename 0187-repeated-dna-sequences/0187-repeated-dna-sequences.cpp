class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> mp;
        vector<string> ans;
        if(s.length() < 10) {
            return {};
        }
        
        for(int i = 10, j = 0; j <= s.length() - 10; i++, j++) {
            string curr = s.substr(j, 10);
            mp[curr]++;
        }
        
        for(auto m : mp) {
            if(m.second > 1) {
                ans.push_back(m.first);
            }
        }
        
        return ans;
    }
};