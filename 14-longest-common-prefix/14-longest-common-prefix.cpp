class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int len = strs[0].length();
        int n = strs.size();
        
        for(int i = 0; i < len; i++) {
            bool flag = true;
            
            char prev = strs[0][i];
            
            for(int j = 0; j < n; j++) {
                if(strs[j][i] != prev) {
                    flag = false;
                    break;
                }
            }
            
            if(flag == false) {
                break;
            }else ans += prev;
        }
        
        return ans;
    }
};