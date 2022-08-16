class Solution {
public:
    int myAtoi(string s) {
        int sign = 0, negative = 0;
        long long int ans = 0;
        int nums = 0;
        int n = s.length();
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '-' || s[i] == '+') {
                if(nums > 0) {
                    break;
                }
                if(s[i] == '-') {
                    negative++;
                }
                sign++;
            }
            if(sign > 1) {
                return 0;
            }
            
            if(s[i] == '.') {
                break;
            }
            if(s[i] >= 48 && s[i] <= 57) {
                ans = ans*10 + (s[i] - 48);
                if(ans > INT_MAX) {
                    if(negative > 0) {
                        return INT_MIN;
                    }
                    return INT_MAX;
                }else if(ans < INT_MIN) {
                    
                    return INT_MIN;
                }
                nums++;
            }else if(s[i] == ' ' || s[i] == '-' || s[i] == '+') {
                if(nums > 0 || (sign > 0 && s[i] == ' ')) {
                    break;
                }
            }else {
                break;
            }
        }
        
        if(negative > 0) {
            ans *= -1;
        }
        
        if(ans < INT_MIN) {
            return INT_MIN;
        }
        if(ans > INT_MAX) {
            return INT_MAX;
        }
        return ans;
    
    }
};