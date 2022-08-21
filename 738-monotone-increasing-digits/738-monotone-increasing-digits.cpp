class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int len = str.length();
        int mark = len;
        
        for(int i = len -1; i > 0; i--) {
            if(str[i] < str[i - 1]) {
                mark = i;
                str[i - 1]--;
            }
        }
        
        for(int i = mark; i < len; i++) {
            str[i] = '9';
        }
        
        return stoi(str);
    }
};