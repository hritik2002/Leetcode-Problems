class Solution {
public:
    bool checkForPossible(vector<int> &price, int k, int diff) {
        int cnt = 1;
        int curr = price[0];
        
        for(int i = 1; i < price.size(); i++) {
            if((price[i] - curr) >= diff) {
                cnt++;
                curr = price[i];
            }
        }
        
        if(cnt >= k) {
            return true;
        }
        
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int ans = 0;
        int lowest_possible_ans = 0, highest_possible_ans = price[n - 1] - price[0];
        
        while(lowest_possible_ans <= highest_possible_ans) {
            int mid = lowest_possible_ans + (highest_possible_ans - lowest_possible_ans) / 2;
            
            if(checkForPossible(price, k, mid)) {
                ans = max(ans, mid);
                lowest_possible_ans = mid + 1;
            }else highest_possible_ans = mid - 1;
        }
        
        return ans;
    }
};