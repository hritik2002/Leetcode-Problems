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
            if(arr[i][1]>=truckSize){
                ans += arr[i][0]*truckSize;
                truckSize = 0 ;
            }else{
                ans += arr[i][0]*arr[i][1];
                truckSize -= arr[i][1];
                arr[i][1] = 0 ;
            }
            if(truckSize==0)break;
        }
        return ans;
    }
};