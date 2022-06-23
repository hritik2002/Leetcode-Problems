class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int min_diff = INT_MAX , n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-1;i++){
            min_diff = min(min_diff,abs(arr[i+1]-arr[i]));
        }
        vector<vector<int>>ans;
        for(int i=0;i<n-1;i++){
            if(min_diff==abs(arr[i+1]-arr[i])){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};