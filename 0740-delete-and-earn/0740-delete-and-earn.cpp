class Solution {
public:
    vector<int> dp;
    int dfs(vector<int> &arr, int ind) {
        if(ind >= arr.size()) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        
        int i = ind;
        int currSum = 0;
        
        while(i < arr.size() && arr[i] == arr[ind]) {
            currSum += arr[i];
            i++;
        }
        while(i < arr.size() && arr[i] == arr[ind] + 1) {
            i++;
        }
        
        return dp[ind] = max(currSum + dfs(arr, i), dfs(arr, ind + 1));
    }
    
    int deleteAndEarn(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);
        sort(nums.begin(), nums.end());
        
        return dfs(nums, 0);
    }
};