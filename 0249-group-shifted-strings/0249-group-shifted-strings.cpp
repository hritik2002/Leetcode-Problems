class Solution {
public:
    
    string getHash(string &str) {
        string hash = "";
        
        for(int i = 1; i < str.length(); i++) {
            hash += (str[i] - str[i - 1] + 26) % 26 + 'a';
        }
        
        return hash;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string>> mp;
        vector<vector<string>> ans;
        
        for(auto str : strings) {
            mp[getHash(str)].push_back(str);
        }
        
        for(auto m : mp) {
            ans.push_back(m.second);
        }
        
        return ans;
    }
};