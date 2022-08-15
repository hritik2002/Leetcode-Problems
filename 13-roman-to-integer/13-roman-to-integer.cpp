class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;

        
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        
        int n = s.length();
        long long int ans = 0;
        
        for(int i = n - 1; i >= 0; i--) {
            if(i >= 1 && (mp[s[i]] > mp[s[i - 1]] ))  {
                ans += mp[s[i]] - mp[s[i - 1]];
                i--;
            }else {
                ans += mp[s[i]];
            }
        }
        
        return ans;
    }
};