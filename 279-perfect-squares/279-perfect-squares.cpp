class Solution {
public:
    int numSquaresReal(int n) {
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        int a = -1, b = sqrt(n);
        n -= b * b;
        b += b + 1;
        while (a <= b) {
            if (n < 0)
                n += b -= 2;
            else if (n > 0)
                n -= a += 2;
            else
                return a < 0 ? 1 : 2;
        }
        
        return 3;
    }

    int numSquares(int n) {
        int sum = 0;
        for (int i=0; i<10000; i++)
            sum += numSquaresReal(n);
        
        return sum / 10000;
    }
};