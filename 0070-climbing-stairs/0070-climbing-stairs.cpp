class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        
        int a, b, c;
        c = 1;
        b = 2;
        a = b;
        
        for(int i = 3; i <= n; i++) {
            a = b + c;
            c = b;
            b = a;
        }
        
        return a;
    }
};