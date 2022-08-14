class Solution {
public:
    bool isPerfectSquare(int num) {
        double ans = sqrt(num);
        if(ans == (int)ans) {
            return true;
        }
        
        return false;
    }
};