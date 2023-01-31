class Solution {
public:
    int getLongestLength(string s, char ch, int k) {
        int start = 0, end = 0;
        int len = s.length();
        int ans = 0;
        
        while(end < len) {
            while(end < len && (k || (ch == s[end]))) {
                if(ch != s[end]) {
                    k--;
                }
                
                end++;
            }
            
            ans = max(ans, end - start);
            
            if(ch != s[start]) {
                k++;
            }
            
            start++;
        }
        
        return ans;
    }
    int characterReplacement(string s, int k) {
        int ans = 0;
        
        for(char a = 'A'; a <= 'Z'; a++) {
            ans = max(ans, getLongestLength(s, a, k));
        }
        
        return ans;
    }
};


// change to prev char
// or change to next char
// or don't change and move to the next element