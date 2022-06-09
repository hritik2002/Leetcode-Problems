class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        long ans = 0 ;
        vector<int>dup = arr ;
        long long sum1 = 0 , sum2 = 0 ;
        sort(arr.begin(),arr.end());
        for(int i=0 ; i<arr.size();i++){
            sum1 += arr[i];
            sum2 += dup[i];
            if(sum1==sum2){
                ans++;
            }
        }
        return ans;
    }
};