class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stck;
        int len = s.length();
        
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') {
                stck.push(i);
            }else if(s[i] == ')') {
                if(!stck.empty()) {
                    stck.pop();
                }else s[i] = '*';
            }
        }
        
        while(!stck.empty()) {
            auto top = stck.top();
            stck.pop();
            
            s[top] = '*';
        }
        
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        
        return s;
    }
};