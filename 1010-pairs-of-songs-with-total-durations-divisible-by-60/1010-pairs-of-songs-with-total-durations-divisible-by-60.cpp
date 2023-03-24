class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt = 0;
        map<int, int> mp;
        
        for(auto t : time) {
            if(mp[60 - (t % 60)]) {
                cnt += mp[60 - (t % 60)];
            }
            
            if(t % 60 == 0)
                cnt += mp[(t % 60)];
            
            mp[(t % 60)]++;
        }
        
        return cnt;
    }
};