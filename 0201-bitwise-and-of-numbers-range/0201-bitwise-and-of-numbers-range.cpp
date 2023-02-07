class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int m = left, n = right;
        
        while(m < n) {
            n = (n & (n - 1));
        }
        
        return m & n;
    }
};