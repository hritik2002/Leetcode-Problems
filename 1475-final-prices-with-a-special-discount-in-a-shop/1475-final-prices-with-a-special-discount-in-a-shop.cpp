class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> stck;
        vector<int> ans(prices.size());
        
        for(int i = prices.size() - 1; i >= 0; i--) {
            while(stck.size() && stck.top() > prices[i]) {
                stck.pop();
            }
            if(stck.size()) {
                ans[i] = prices[i] - stck.top();
            }else {
                ans[i] = prices[i];
            }
            
            stck.push(prices[i]);
        }
        
        return ans;
    }
};