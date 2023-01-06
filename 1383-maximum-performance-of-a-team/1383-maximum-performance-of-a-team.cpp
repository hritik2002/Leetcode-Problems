class Solution {
public:
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<vector<int>> engineer(n, vector<int> (2));
        
        for(int i = 0; i < n; i++) {
            engineer[i] = {efficiency[i], speed[i]};
        }
        sort(rbegin(engineer), rend(engineer));
        long long totalSpeed = 0, ans = 0;
        
        for(auto eng : engineer) {
            long long currSpeed = eng[1], effi = eng[0];
            totalSpeed += currSpeed;
            pq.push(currSpeed);
            k--;
            
            if(k < 0) {
                totalSpeed -= pq.top();
                pq.pop();
                k++;
            }
            
            ans = max(ans, totalSpeed * effi);
        }
        
        return ans % mod;
    }
};