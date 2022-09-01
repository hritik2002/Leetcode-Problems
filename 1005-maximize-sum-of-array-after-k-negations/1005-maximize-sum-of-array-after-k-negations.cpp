class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            pq.push(nums[i]);
            sum += nums[i];
        }
        
        while(k--) {
            int top = pq.top();
            pq.pop();
            sum -= top;
            
            top *= -1;
            pq.push(top);
            sum += top;
        }
       
        return sum;
        
    }
};