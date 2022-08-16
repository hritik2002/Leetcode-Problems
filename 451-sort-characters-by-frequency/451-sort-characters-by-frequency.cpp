class Solution {
public:
    static bool sortFn(pair<char, int> arg1, pair<char, int> arg2) {
        return arg1.second > arg2.second;
    }
    
    string frequencySort(string s) {
        vector<pair<char, int>> count(256);
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            count[s[i]] = {s[i], count[s[i]].second + 1};
        }
        
        sort(count.begin(), count.end(), sortFn);
        
        string ans = "";
        
        for(int i = 0; i < 256; i++) {
            int charCount = count[i].second;
            
            while(charCount--) {
                ans += count[i].first;
            }
        }
        
        return ans;
    }
};