class Solution {
public:
    vector<int> counter(string s) {
        vector<int> ans(26, 0);
        
        for(auto c : s) {
            ans[c - 'a']++;
        }
        
        return ans;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> cnt(26, 0), tmp(26, 0);
        
        for(auto b : words2) {
            tmp = counter(b);
            
            for(int i = 0; i < 26; i++) {
                cnt[i] = max(cnt[i], tmp[i]);
            }
        }
        
        for(auto a : words1) {
            tmp = counter(a);
            int i = 0;
            for( i = 0; i < 26; i++) {
                if(tmp[i] < cnt[i]) {
                    break;
                }
            }
            
            if(i == 26) {
                ans.push_back(a);
            }
        }
        
        
        
        return ans;
    }
};