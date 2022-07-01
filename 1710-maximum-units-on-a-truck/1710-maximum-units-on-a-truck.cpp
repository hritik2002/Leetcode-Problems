class Solution {
public:
    int maximumUnits(vector<vector<int>>& arr, int truckSize) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            int temp = arr[i][0];
            arr[i][0] = arr[i][1];
            arr[i][1] = temp ;
        }
        sort(arr.begin(),arr.end());
        int ans = 0 ;
        for(int i=n-1;i>=0 ;i--){
            while(truckSize>0 &&arr[i][1]-- ){
                ans += arr[i][0];
                truckSize--;
            }
        }
        return ans;
    }
};