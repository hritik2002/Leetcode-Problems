class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int sum = 0;
        priority_queue<int> pq;
        
        for(auto c : courses) {
            sum += c[0];
            pq.push(c[0]);
            
            if(sum > c[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};