class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(256, 0);
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            count[s[i]]++;
        }
        
        for(int i = 0; i < n; i++) {
            if(count[s[i]] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};