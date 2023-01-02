class Solution {
public:
    bool detectCapitalUse(string word) {
        if(toupper(word[0]) == word[0]) {
            int cnt = 1;
            for(int i = 1; i < word.length(); i++) {
                if(toupper(word[i]) == word[i]) {
                    if(cnt == -1)
                        return false;
                    
                    cnt++;
                }else if(toupper(word[i]) != word[i]) {
                    if(cnt > 1) return false;
                    
                    cnt = -1;
                }
            }
        }else {
            bool flag = false;
            for(int i = 1; i < word.length(); i++) {
                if(flag == false && toupper(word[i]) == word[i]) {
                    return false;
                }else if(toupper(word[i]) != word[i]) {
                    flag = false;
                }
            }
        }
        
        return true;
    }
};