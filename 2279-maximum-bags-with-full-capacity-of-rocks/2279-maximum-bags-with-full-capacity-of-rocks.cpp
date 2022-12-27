class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff;
        
        for(int i = 0; i < capacity.size(); i++) {
            diff.push_back(capacity[i] - rocks[i]);
        }
        
        sort(diff.begin(), diff.end());
        int cnt = 0;
        
        for(int i = 0; i < diff.size(); i++) {
            if(diff[i] == 0) {
                cnt++;
            }else {
                if(additionalRocks >= diff[i]) {
                    cnt++;
                    additionalRocks -= diff[i];
                }
            }
        }
        
        return cnt;
    }
};