class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26,0);
        
        for(auto letter : s){
            arr[letter - 'a']++;
        }
        for(auto letter : t){
            arr[letter - 'a']--;
        }
        
        for(int i=0 ; i < 26; i++){
            if(arr[i] != 0)return false;
        }
        
        return true;
    }
};