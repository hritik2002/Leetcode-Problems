class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        long long sum = 0;
        priority_queue<long long> pq;
        
        for(auto stone : piles) {
            sum += stone;
            pq.push(stone);
        }
        
        while(k--) {
            long long top = pq.top();
            pq.pop();
            sum -= top;
            
            top = floor((top + 1)/ 2);
            sum += top;
            
            pq.push(top);
        }
        
        return sum;
    }
};