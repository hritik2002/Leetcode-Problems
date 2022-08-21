class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int count[256] = {0};
        vector<int> arr(n, -1);
        
        for(int i = 0; i < n; i++) {
            count[s[i]]++;
        }
        
        int l = 0, r = n - 1;
        for(int i = 0; i < 256; i++) {
            while(count[i] >= 2) {
                arr[l] = i;
                arr[r] = i;
                l++;
                r--;
                count[i] -= 2;
            }
        }
        
        if(l <= r) {
            for(int i = 0; i < 256; i++) {
                if(count[i]) {
                    arr[l] = i;
                    break;
                }
            }
        }
        
        string ans = "";
        
        for(int i = 0; i < n; i++) {
            if(arr[i] != -1) {
                ans += 'a' + arr[i];
            }
        }
        
        return ans.length();
    }
};