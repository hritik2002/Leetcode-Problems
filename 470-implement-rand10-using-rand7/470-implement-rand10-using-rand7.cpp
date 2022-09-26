// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    stack<int> cache;
    
    int rand10() {
        while (cache.size() == 0) generate();
        int res = cache.top(); cache.pop();
        
        return res;
    }

    void generate() {
        int n = 19;
        long cur = 0, range = long(pow(7, n));
        for (int i = 0; i < n; ++i) cur += long(pow(7, i)) * (rand7() - 1);
        while (cur < range / 10 * 10) {
            cache.push(cur % 10 + 1);
            cur /= 10;
            range /= 10;
        }
    }

};