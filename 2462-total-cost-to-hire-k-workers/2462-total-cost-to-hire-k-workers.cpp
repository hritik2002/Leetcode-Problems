class Solution {
public:
    long long totalCost(vector<int>& cos, int k, int can) {
        long long ans=0;
        priority_queue<int, vector<int>, greater<int> > pq1;    // min heap
        priority_queue<int, vector<int>, greater<int> > pq2;    // min heap
        int i=0, j = cos.size() - 1;
        
        while(k--) {
            while(pq1.size() < can && i <= j) {
                pq1.push(cos[i++]);
            }
            while(pq2.size() < can && i <= j) {
                pq2.push(cos[j--]);
            }
            int a = pq1.size() ? pq1.top() : INT_MAX;
            int b = pq2.size() ? pq2.top() : INT_MAX;
            
            if(a <= b) {
                ans += a;
                pq1.pop();
            }else {
                ans += b;
                pq2.pop();
            }

        }
            
        return ans;
    }
};