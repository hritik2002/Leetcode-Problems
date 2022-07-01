class Solution {
public:
    int sum_of_arr(vector<int>&arr,int value){
        int sum = 0 ;
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>value){
                sum += value ;
            }else sum += arr[i];
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int low = 0, high = 100000;
        int ans = INT_MAX ;
        while(low<=high){
            int mid = low + (high-low)/2;
            int converted_to_mid = sum_of_arr(arr,mid);
            int converted_to_mid_plus1 = sum_of_arr(arr,mid+1);
            if(abs(converted_to_mid-target)<=abs(converted_to_mid_plus1-target)){
                ans = min(ans,mid);
                high = mid-1 ;
            }else low = mid + 1 ;
        }
        return ans;
    }
};