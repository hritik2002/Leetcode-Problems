class Solution {
public:
    int minInsertions(string s) {
        int count = 0, ans = 0;
        int i = 0, len = s.length();
        stack<char> _stack;
        
        while(s[i] != '/0' && s[i] == ')') {
            count++;
            
            if(count == 2) {
                ans++;
                count = 0;
            }
            
            i++;
        }
        
        if(count == 2) {
            ans++;
        }else if(count == 1) {
            ans += 2;
        }
        
        for( ; i < len; i++) {
            if(s[i] == '(') {
                _stack.push(s[i]);
            }else {
                if(i + 1 < len && s[i + 1] == ')') {
                    if(_stack.size()) {
                        _stack.pop();
                    }else {
                        ans++;
                    }
                    i++;
                }else if(i + 1 < len && s[i + 1] != ')'){
                    if(_stack.size()) {
                        _stack.pop();
                        ans++;
                    }else {
                        ans += 2;
                    }
                }else {
                    if(_stack.size()) {
                        _stack.pop();
                        ans++;
                    }else {
                        ans += 2;
                    }
                }
            }
        }
        
        while(_stack.size()) {
            ans += 2;
            _stack.pop();
        }
        
        return ans;
    }
};