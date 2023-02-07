class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = n & 1;
        n = n >> 1;
        
        while(n) {
            int currBit = n & 1;
            
            if(currBit == prevBit) {
                return false;
            }
            
            prevBit = currBit;
            n = n >> 1;
        }
        
        return true;
    }
};