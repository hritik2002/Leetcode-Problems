class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int end = 0, begin = 0;
        int ans = 0, len = s.length();
        map<char, int> mp;
        
        while(end < len) {
            mp[s[end]]++;
            
            while(mp.size() > k) {
                mp[s[begin]]--;
                if(mp[s[begin]] == 0) {
                    mp.erase(s[begin]);
                }
                
                begin++;
            }
            
            ans = max(ans, end - begin + 1);
            end++;
        }
        
        return ans;
    }
};