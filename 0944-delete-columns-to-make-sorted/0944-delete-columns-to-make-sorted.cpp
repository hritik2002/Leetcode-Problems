class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cnt = 0;
        
        for(int i = 0; i < strs[0].length(); i++) {
            string tmp = "";
            for(int j = 0; j < strs.size(); j++) {
                tmp += strs[j][i];
            }
            
            string sorted = tmp;
            sort(sorted.begin(), sorted.end());
            
            if(tmp != sorted) {
                cnt++;
            }
        }
        
        return cnt;
    }
};