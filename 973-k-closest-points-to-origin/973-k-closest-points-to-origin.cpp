#define pi pair<double, vector<int>>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi> pq;
        vector<vector<int>> ans;
        
        for(auto arr: points) {
            double dist = sqrt(arr[0]*arr[0] + arr[1]*arr[1]);
            
            if(pq.size() < k) {
                pq.push({dist, arr});
            }else if(dist < pq.top().first) {
                pq.pop();
                pq.push({dist, arr});
            }
        }
        
        while(pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};