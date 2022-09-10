class Solution {
public:
    int minSwaps(string s) {
        int count = 0, len = s.length();
        
        for(int i = 0; i < len; i++) {
            if(s[i] == '[') {
                count++;
            }else {
                if(count) {
                    count--;
                }
            }
        }
        
        return (count + 1) / 2;
    }
};