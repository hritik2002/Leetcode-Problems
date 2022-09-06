class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        string rev = num;
        reverse(rev.begin(), rev.end());
        
        if(num == rev) {
            return true;
        }
        
        return false;
    }
};