class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0, sum1 = 0, sum2 = 0;
        int mod = 1e9 + 7;
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        
        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                sum1 += nums1[i];
                i++;
            }else if(nums2[j] < nums1[i]) {
                sum2 += nums2[j];
                j++;
            }else {
                ans += nums2[j] + max(sum1, sum2);
                sum1 = 0, sum2 = 0;
                i++;
                j++;
            }
        }
        while(i < n) {
            sum1 += nums1[i];
            i++;
        }
        while(j < m) {
            sum2 += nums2[j];
            j++;
        }
        ans = ans + max(sum1, sum2);
        
        return ans % mod;
    }
};