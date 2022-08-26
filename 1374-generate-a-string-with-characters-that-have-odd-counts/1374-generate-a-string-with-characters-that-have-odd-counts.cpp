class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        if(n % 2 == 0) {
            while(n--) {
                ans += 'a';
            }
            
            ans[0] = 'b';
            
        }else {
            while(n--) {
                ans += 'a';
            }
        }
        
        return ans;
    }
};