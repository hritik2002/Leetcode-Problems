class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, avg = 0, sum = 0, n = arr.size(), left = 0, right = 0;
        
        while(right < k) {
            sum += arr[right++];
        }
        
        if(sum / k >= threshold) {
            ans++;
        }
        
        while(right < n) {
            sum -= arr[left++];
            sum += arr[right++];
            
            if(sum / k >= threshold) {
                ans++;
            }
        }
        
        return ans;
    }
};