class Solution {
public:
    vector<int> dp;
    bool canReach0(vector<int> &arr, int index, vector<bool>& visited) {
        if(index < 0 || index >= arr.size()) {
            return false;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        if(visited[index]) {
            return false;
        }
        if(arr[index] == 0) {
            return true;
        }
        
        int steps = arr[index];
        visited[index] = true;
        
        if(canReach0(arr, index + steps, visited)) {
            return dp[index] = 1;
        }
        if(canReach0(arr, index - steps, visited)) {
            return dp[index] = 1;
        }

        visited[index] = false;
        
        return dp[index] = 0;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visisted(arr.size(), false);
        dp.resize(arr.size(), -1);
        
        return canReach0(arr, start, visisted);
    }
};