class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int div = 5;
        
        while(n >= div) {
            ans += n / div;
            div *= 5;
        }
        
        return ans;
    }
};