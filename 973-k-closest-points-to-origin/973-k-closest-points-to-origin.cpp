class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<double>distance(n,0);
        for(int i=0;i<n;i++){
            double square_sum = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            double dist =  sqrt(square_sum);
            distance[i] = dist ;
        }
        vector<vector<int>>ans;
        vector<pair<double,int>>dist(n);
        for(int i=0;i<n;i++){
            pair<double,int>temp ;
            temp.first = distance[i];
            temp.second = i ;
            dist[i] = temp ;
        }
        sort(dist.begin(),dist.end());
        int i = 0 ;
        while(k--){
            ans.push_back(points[dist[i].second]);
            i++;
        }
        return ans;
    }
};