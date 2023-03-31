class Solution {
public:
    long long _largestEvenSum(vector<int>& nums, int k) {
        // step1: Get even and odd numbers
        vector<int> even, odd;
        long long ans = 0;
        if(k > nums.size()) {
            return -1;
        }
        
        for(auto num : nums) {
            if(num % 2) {
                odd.push_back(num);
            }else {
                even.push_back(num);
            }
        }
        int i = even.size() - 1;
        int j = odd.size() - 1;
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        
        while(k) {
            // if k is odd
            if(k % 2) {
                // only add even
                if(i >= 0) {
                    ans += even[i];
                    i--;
                    k--;
                }else {
                    return -1;
                }
            }else {
                if(i >= 1 && j >= 1) {
                    if(even[i] + even[i - 1] <= odd[j] + odd[j - 1]) {
                        ans += odd[j] + odd[j - 1];
                        j -= 2;
                        k -= 2;
                    }else {
                        ans += even[i] + even[i - 1];
                        i -= 2;
                        k -= 2;
                    }
                }else if(i >= 1) {
                        ans += even[i] + even[i - 1];
                        i -= 2;
                        k -= 2;
                }else if(j >= 1){
                        ans += odd[j] + odd[j - 1];
                        j -= 2;
                        k -= 2;
                }else return -1;
            }
        }
        
        if(ans % 2) return -1;
        
        return ans;
    }
    long long largestEvenSum(vector<int>& nums, int k) {
        return _largestEvenSum(nums, k);
    }
};