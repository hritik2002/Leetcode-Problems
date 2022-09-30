class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, n = g.size(), m = s.size();
        int cnt = 0;
        
        while(i < n && j < m) {
            int a = g[i];
            int b = s[j];
            
            if(b >= a) {
                j++;
                i++;
                cnt++;
            }else {
                j++;
            }
        }
        
        return cnt;
    }
};