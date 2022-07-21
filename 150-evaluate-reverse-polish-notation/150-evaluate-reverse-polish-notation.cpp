class Solution {
public:
    int performOperation(int first, int second, string op){
        if(op == "+")
            return first + second;
        if(op == "-")
            return first - second;
        if(op == "*")
            return first * second;
        if(op == "/") 
            return first / second;
        
        return 0;
    }
        
    int evalRPN(vector<string>& tokens) {
        int res = 0, n = tokens.size();
        stack<string> stck;
        
        if(n == 1)return stoi(tokens[0]);
        
        for(int i = 0; i < n; i++){
            if(tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "-" || tokens[i] == "+"){
                string second_element = stck.top();
                stck.pop();
                string first_element = stck.top();
                stck.pop();
                
                res = performOperation(stoi(first_element), stoi(second_element), tokens[i]);
                stck.push(to_string(res));
            }else{
                stck.push(tokens[i]);
            }
        }
        return res ;
    }
};