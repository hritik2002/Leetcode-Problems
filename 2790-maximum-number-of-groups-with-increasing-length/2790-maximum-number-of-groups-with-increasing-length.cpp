class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        long long total = 0, count = 0;
        
        sort(usageLimits.begin(), usageLimits.end());
        
        for(auto usage : usageLimits) {
            total += usage;
            
            if(total >= ((count + 1) * (count + 2) / 2)) {
                count++;
            }
        }
        
        return count;
    }
};