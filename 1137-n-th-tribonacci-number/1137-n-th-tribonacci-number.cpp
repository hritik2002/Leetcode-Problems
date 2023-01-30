class Solution {
public:
    int tribonacci(int n) {
        long long a = 0, b = 1, c = 1;
        long long sum = a + b + c;
        int cnt = 3;
        if(n == 0 || n == 1) {
            return n;
        }else if(n == 2) {
            return 1;
        }
        
        while(cnt <= n) {
            sum = a + b + c;
            a = b;
            b = c;
            c = sum;
            cnt++;
        }
        
        return sum;
    }
};