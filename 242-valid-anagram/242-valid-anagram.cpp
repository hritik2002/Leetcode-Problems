class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int> hm;
        
        for(auto letter : s){
            hm[letter]++;
        }
        for(auto letter : t){
            hm[letter]--;
        }
        
        for(auto __map : hm){
            if(__map.second != 0)return false;
        }
        
        return true;
    }
};