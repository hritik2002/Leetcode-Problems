class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cntFlips = 0, cnt1 = 0;
        
        for(auto c : s) {
            if(c == '1') {
                cnt1++;
            }else {
                cntFlips++;
                cntFlips = min(cnt1, cntFlips);
            }
        }
        
        return cntFlips;
    }
};