class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> ans;
        map<string, vector<int>> mp;
        
        for(int i = 0; i < size; i++) {
            string str = strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(i);
        }
        
        for(auto _map : mp) {
            vector<string> anagram;
            
            for(auto index : _map.second) {
                anagram.push_back(strs[index]);
            }
            
            ans.push_back(anagram);
        }
        
        return ans;
    }
};