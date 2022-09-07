class Solution {
public:
    int strStr(string haystack, string needle) {
        int start = 0, n = haystack.size(), m = needle.size();
        
        while(start < n) {
            if(haystack[start] == needle[0]) {
                int i = 0, j = start;
                bool flag = true;
                
                while(i < m) {
                    if(haystack[j] != needle[i]) {
                        flag = false;
                        break;
                    }
                    
                    i++;
                    j++;
                }
                
                if(flag) {
                    return start;
                }
            }
            
            start++;
        }
        
        return -1;
    }
};