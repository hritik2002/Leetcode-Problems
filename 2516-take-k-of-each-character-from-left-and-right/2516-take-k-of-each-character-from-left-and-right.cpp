class Solution {
public:
    int takeCharacters(string s, int k) {
        map<char, int> mp;
        int n = s.length();
        int i = 0, j = 0, ans = n, window = 0;
        
        for(auto c : s) {
            mp[c]++;
        }
        
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k) {
            return -1;
        }
        
        for(; i < n; i++) {
            mp[s[i]]--;
            window++;
            
            while(mp[s[i]] < k) {
                mp[s[j]]++;
                window--;
                j++;
            }
            
            ans = min(ans, n - window);
        }
        
        return ans;
    }
};