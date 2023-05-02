class Solution {
public:

    int maxScoreSightseeingPair(vector<int>& values) {
        int curr = 0, ans = 0;
        
        for(int value : values) {
            ans = max(ans, curr + value);
            curr = max(curr, value) - 1;
        }
        
        return ans;
    }
};