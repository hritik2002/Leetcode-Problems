class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        vector<int> hash1(26, INT_MAX);
        vector<int> hash2(26, 0);
        int n = words.size();
        
        
        for(int i = 0; i < n; i++) {
            for(auto c : words[i]) {
                hash2[c - 'a']++;
            }
            
            for(int i = 0; i < 26; i++) {
                hash1[i] = min(hash2[i], hash1[i]);
                hash2[i] = 0;
            }
        }
        
        vector<string> ans;
        
        for(int i = 0; i < 26; i++) {
            if(hash1[i] > 0 && hash1[i] < INT_MAX) {
                char c = i + 'a';
                string s = "";
                s += c;
                
                int count = hash1[i];
                while(count--)
                    ans.push_back(s);
            }
        }   

        return ans;
        
    }
};