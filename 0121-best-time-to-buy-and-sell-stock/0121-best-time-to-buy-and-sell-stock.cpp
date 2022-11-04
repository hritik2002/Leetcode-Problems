class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size(), sum = 0;
        
        for(int i = 1; i < n; i++) {
            sum += prices[i] - prices[i - 1];
            sum = max(sum, 0);
            ans = max(sum, ans);
        }
        
        return ans;
    }
};