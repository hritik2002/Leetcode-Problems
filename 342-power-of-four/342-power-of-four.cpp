class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0) {
            return false;
        }
    
        double ans = log(n) / log(4);
        
        if(ans == trunc(ans)) {
            return true;
        }
        
        return false;
    }
};