class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> count;
        
        for(auto letter : s){
            count[letter]++;
        }
        for(auto letter : t){
            count[letter]--;
        }
        
        for(auto __map : count){
            if(__map.second != 0)return false;
        }
        
        return true;
    }
};