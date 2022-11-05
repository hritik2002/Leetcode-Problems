class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 3, vector<int> (2, 0));
        
        for(int day = n + 2; day >= 0; day--) {
            for(int buy = 0; buy < 2; buy++) {
                if(day >= n) {
                    dp[day][buy] = 0;
                }else {
                    int &ans = dp[day][buy];
                    int ans1 = dp[day + 1][buy], ans2 = 0;
                    
                    if(buy) {
                        ans2 = -prices[day] + dp[day + 1][0];
                    }else ans2 = prices[day] + dp[day + 2][1];
                    
                    ans = max(ans1, ans2);
                }
            }
        }
        
        
        return dp[0][1];
    }
};