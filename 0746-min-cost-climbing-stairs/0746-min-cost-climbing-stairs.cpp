class Solution {
public:
    vector<long long> dp;
    long long minCost(vector<int>& cost, int ind) {
        if(ind <= 1) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        
        long long oneDown = (long long) cost[ind - 1] + minCost(cost, ind - 1);
        long long twoDown = (long long) cost[ind - 2] + minCost(cost, ind - 2);
        
        return dp[ind] = min(oneDown, twoDown);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size() + 1, -1);
        
        return minCost(cost, cost.size());
    }
};