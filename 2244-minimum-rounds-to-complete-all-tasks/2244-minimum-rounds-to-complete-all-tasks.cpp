class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        
        for(auto task : tasks) {
            mp[task]++;
        }
        int cnt = 0;
        for(auto x : mp) {
            if(x.second < 2) {
                return -1;
            }else {
                cnt += x.second / 3;
                
                if(x.second % 3) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};