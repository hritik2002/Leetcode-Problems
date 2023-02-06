class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        
        int prev = pairs[0][1];
        int cnt = 1;
        
        for(int i = 1; i < pairs.size(); i++) {
            if(pairs[i][0] > prev) {
                cnt++;
                prev = pairs[i][1];
            }
        }
        
        return cnt;
    }
};