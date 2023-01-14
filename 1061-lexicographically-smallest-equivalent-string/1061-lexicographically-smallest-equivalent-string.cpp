class Solution {
public:
    int find(int x, vector<int>& parent) {
        if(parent[x] == x) {
            return x;
        }
        
        return parent[x] = find(parent[x], parent);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string ans = "";
        int n = s1.length();
        vector<int> parent(26, 0);
        for(int i = 0; i < 26; i++) parent[i] = i;
        
        for(int i = 0; i < n; i++) {
            int x = find(s1[i] - 'a', parent);
            int y = find(s2[i] - 'a', parent);
            
            if(x < y) {
                parent[y] = x;
            }else parent[x] = y;
        }
        
        n = baseStr.length();
        
        for(int i = 0; i < n; i++) {
            int x = find(baseStr[i] - 'a', parent);
            
            ans += (x + 'a');
        }
        
        return ans;
    }
};