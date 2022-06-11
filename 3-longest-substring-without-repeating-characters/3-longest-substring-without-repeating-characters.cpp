class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char,int>_map;
        int _max = 0, len = 0,start=0;
        for(int i=0 ; i<s.length(); i++){
            while(_map[s[i]]==1){
                _map[s[start++]] = 0;
                len--;
            }
            _map[s[i]]=1;
            len++;
            _max=max(_max,len);
        }
        return _max;

    }
};