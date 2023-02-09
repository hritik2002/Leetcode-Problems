class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        map<char, set<string>> mp;
        long long res = 0;
        
        for(auto idea : ideas) {
            mp[idea[0]].insert(idea.substr(1));
        }
        
        for(char ch = 'a'; ch <= 'z'; ch++) {
            for(char jh = ch + 1; jh <= 'z'; jh++) {
                long long total1 = 0, total2 = 0;
                
                for(auto child : mp[ch]) {
                    if(!mp[jh].count(child)) {
                        total1++;
                    }
                }
                for(auto child : mp[jh]) {
                    if(!mp[ch].count(child)) {
                        total2++;
                    }
                }
                
                res += total1 * total2;
            }
        }
        
        return res * 2;
    }
};