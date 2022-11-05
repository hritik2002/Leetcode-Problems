class Solution {
public:
    vector<vector<int>> dp;
    int solveRec(vector<int> &prices, bool buy, int i) {
        if(i >= prices.size()) {
            return 0;
        }
        
        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }
        
        int ans1 = solveRec(prices, buy, i + 1);
        
        int ans2 = 0;
        if(buy) {
            ans2 = -prices[i] + solveRec(prices, false, i + 1);
        }else 
            ans2 = prices[i] + solveRec(prices, true, i + 2);
        
        return dp[i][buy] = max(ans1, ans2);
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(5001, vector<int> (2, -1));
        return solveRec(prices, true, 0);
    }
};