class Solution {
public:
    
    string smallestNumber(string pattern) {
        string ans = "";
        stack<string> stck;
        
        if(pattern[0] == 'I') {
            ans += "1";
        }else stck.push("1");
        
        int n = pattern.size();
        
        for(int i = 1; i <= n; i++) {
            if(pattern[i - 1] == 'I') {
                while(stck.size() > 0) {
                    ans += stck.top();
                    stck.pop();
                }
            }
            string temp = to_string(i + 1);
            stck.push(temp);
        }
        
        while(stck.size() > 0) {
            ans += stck.top();
            stck.pop();
        }
        
        return ans;
    }
};