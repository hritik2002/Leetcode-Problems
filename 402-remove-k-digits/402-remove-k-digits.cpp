class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stck;
        
        for(int i = 0; i < num.length(); i++) {
            while(k > 0 && stck.size() && num[i] < stck.top()) {
                stck.pop();
                k--;
            }
            
            stck.push(num[i]);
            
            if(stck.size() == 1 && stck.top() == '0') {
                stck.pop();
            }
        }
        
        while(stck.size() && k > 0) {
            stck.pop();
            k--;
        }
        
        string ans = "";
        
        while(stck.size()) {
            ans += stck.top();
            stck.pop();
        }
        
        if(ans.size() == 0) {
            return "0";
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};