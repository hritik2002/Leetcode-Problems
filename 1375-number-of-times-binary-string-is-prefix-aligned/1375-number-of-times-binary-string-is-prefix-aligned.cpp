class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int j = 1, i = 1, n = flips.size();
        vector<int> arr(n + 2, 0);
        int cnt = 0;
        
        for(i = 0; i < n; i++) {
            arr[flips[i]] = 1;
            if(arr[j] == 1) {
                while(arr[j] == 1) {
                    j++;
                }
                
                j--;
            }
                
            if(arr[j] == 1 && j >= (i + 1)) {
                cnt++;
            }
        }
        
        return cnt;
    }
};