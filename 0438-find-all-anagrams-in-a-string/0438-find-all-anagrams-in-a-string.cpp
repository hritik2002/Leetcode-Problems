class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int cnt = 0;
        map<int, int> mp, ms;
        vector<int> ans;
        int j = 0, n = s.length(), window = p.length();
        
        for(auto c : p) {
            mp[c]++;
            cnt++;
        }
        
        for(int i = 0; i < n; i++) {
            ms[s[i]]++;
            
            if((i - j + 1) < window) {
                if(mp[s[i]] >= ms[s[i]]) {
                    cnt--;
                }
                
                continue;
            }
            
            if(mp.count(s[i])) {
                
                if(mp[s[i]] >= ms[s[i]]) {
                    cnt--;
                }
                
                if(cnt == 0) {
                    ans.push_back(j);
                }
            }
            
            ms[s[j]]--;
            if(mp[s[j]] > ms[s[j]]) {
                cnt++;
            }
            j++;
        }
        
        return ans;
    }
};