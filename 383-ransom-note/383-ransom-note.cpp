class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp;
        int n = magazine.size();
        
        for(int i = 0; i < n; i++) {
            mp[magazine[i]]++;
        }
        
        n = ransomNote.size();
        
        for(int i = 0; i < n; i++) {
            if(!mp[ransomNote[i]]) {
                return false;
            }
            
            mp[ransomNote[i]]--;
        }
        
        return true;
    }
};