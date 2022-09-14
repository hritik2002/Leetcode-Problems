class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int step = 0, n = rungs.size(), stepsAdded = 0;
        
        for(int i = 0; i < n; i++) {
            stepsAdded += (rungs[i] - step - 1) / dist;
            
            step = rungs[i];
        }
    
        return stepsAdded;
    }
};