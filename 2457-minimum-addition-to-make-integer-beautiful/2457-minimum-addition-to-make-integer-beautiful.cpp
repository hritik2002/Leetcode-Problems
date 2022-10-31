class Solution {
public:
    long long sum(long long n) {
        long long sum = 0;
        while(n) {
            sum += n % 10;
            n /= 10;
        }
        
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long mul = 1;
        long long res = 0;
        while(sum(n) > target) {
            res = res + mul*(10 - n % 10);
            n = n / 10 + 1;
            mul *= 10;
        }
        
        return res;
    }
};