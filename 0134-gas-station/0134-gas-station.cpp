class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }
        
        int start = 0, total = 0, n = gas.size();
        
        for(int i = 0; i < n; i++) {
            total += gas[i] - cost[i];
            
            if(total < 0) {
                start = i + 1;
                total = 0;
            }
        }
        
        return start;
    }
    
};