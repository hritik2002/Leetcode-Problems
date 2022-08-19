class Solution {
public:
    static int setBits(int n) {
        int count = 0;
        
        while(n) {
            count += n & 1;
            n = n>>1;
        }
        
        return count;
    }
    
    static bool compare(int a, int b) {
        int c1 = setBits(a);
        int c2 = setBits(b);
        
        if(c1 == c2) {
            return a < b;
        }
        return  c1 < c2;
    }
    vector<int> sortByBits(vector<int>& arr) {
                
        sort(arr.begin(), arr.end(), compare);
        
        return arr;
    }
};