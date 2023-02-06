class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.push_back(folder[0]);
        
        for(int i = 1; i < folder.size(); i++) {
            string str = folder[i];
            auto back = ans.back();
            back += '/';
            
            if(str.compare(0, back.size(), back)) {
                ans.push_back(str);
            }
        }
        
        return ans;
    }
};