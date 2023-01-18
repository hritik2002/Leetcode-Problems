class Solution {
public:
    int preimageSizeFZF(int k) {
        vector<int> arr;
        long long sum = 0, mul = 5;
        int ans = 5;
        
        while(mul < INT_MAX) {
            sum += mul;
            mul *= 5;
            arr.push_back(sum);
        }
        reverse(arr.begin(), arr.end());
        
        for(auto i : arr) {
            k %= i + 1;
            if(k == i) {
                ans = 0;
            }
        }  
        
        return ans;
    }
};