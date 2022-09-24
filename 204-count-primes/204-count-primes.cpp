class Solution {
public:
    vector<bool> nums;
    
    void seive(int n) {
        for(int start = 2; start*start <= n; start++) {
            int i = start*start;
            
            if(nums[i]) {
                while(i <= n) {
                    nums[i] = false;
                    
                    i += start;
                }
            }
        }
    }
    int countPrimes(int n) {
        nums.resize(n + 1, true);
        seive(n);
        
        int cnt = 0;
        
        for(int i = 2; i < n; i++) {
            if(nums[i]) {
                cnt++;
            }
        }
        
        return cnt;
    }
};