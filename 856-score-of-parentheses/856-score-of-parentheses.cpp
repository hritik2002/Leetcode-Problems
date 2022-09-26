class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stck;
        stck.push(0);   // final ans
        
        for(auto paran : s) {
            if(paran == '(') {
                stck.push(0);
            }else {
                auto top = stck.top();
                stck.pop();
                
                if(top) {
                    top *= 2;
                }else top = 1;
                
                stck.top() += top;
            }
        }
        
        return stck.top();
    }
};