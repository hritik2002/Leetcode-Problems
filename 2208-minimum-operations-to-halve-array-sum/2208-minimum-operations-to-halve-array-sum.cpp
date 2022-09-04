#define d double

class Solution {
public:
    int halveArray(vector<int>& nums) {
        d sum = 0;
        int steps = 0;
        priority_queue<d> pq;

        for(auto num : nums) {
            sum += num;
            pq.push(num);
        }
        
        d half = (double)sum*1.0 / 2;
        
        while(pq.size() && sum > half) {
            d top = pq.top();
            pq.pop();
            
            sum -= top;
            top = top / 2;
            
            sum += top;
            pq.push(top);
            
            steps++;
        }
        
        return steps;
    }
};