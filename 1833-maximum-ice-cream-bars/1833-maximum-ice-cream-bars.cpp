class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        
        for(auto c : costs) {
            if(coins - c < 0) {
                break;
            }
            
            cnt++;
            coins -= c;
        }
        
        return cnt;
    }
};