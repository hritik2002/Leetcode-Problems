class Solution {
public:
    int addDigits(int n) {
        int sum = n;
        
        while(n > 9)
        {
 
            sum =  0;
            while(n != 0)
            {
                sum += n % 10;
                n = n / 10;
            }
            
            n = sum;
        }
        
        return sum;
    }
};