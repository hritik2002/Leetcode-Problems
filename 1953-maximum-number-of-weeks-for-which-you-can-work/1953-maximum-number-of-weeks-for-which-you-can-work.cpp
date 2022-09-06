class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        long long sum = accumulate(begin(m), end(m), 0ll);
        long long max = *max_element(begin(m), end(m));
        
        return min(sum, 2 * (sum - max) + 1);
    }
};