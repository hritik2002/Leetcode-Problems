class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<pair<int, int>>& player, int ind, int prevInd) {
        if(ind == player.size()) {
            return 0;
        }
        if(dp[ind][prevInd + 1] != -1) {
            return dp[ind][prevInd + 1];
        }
        
        int ans = 0;
        if(prevInd == -1 || player[ind].second >= player[prevInd].second) {
            ans = player[ind].second + dfs(player, ind + 1, ind);
        }
        
        ans = max(ans, dfs(player, ind + 1, prevInd));
        
        return dp[ind][prevInd + 1] = ans;
    }
    
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> player;
        int n = scores.size();
        dp.resize(n + 1, vector<int> (n + 1, -1));
        
        for(int i = 0; i < n; i++) {
            player.push_back({ages[i], scores[i]});
        }
        
        sort(player.begin(), player.end());
        
        return dfs(player, 0, -1);
    }
};