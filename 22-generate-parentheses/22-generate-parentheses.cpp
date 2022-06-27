class Solution {
public:
    vector<string>ans;
    bool isValid(string s,int n){
        // return true;
        if(n>0 && s[0]==')' || s[n-1]=='(')return false;
        stack<char>stck;
        stck.push(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]==')'){
                if(stck.top()=='('){
                    stck.pop();
                }else{
                    stck.push(s[i]);
                }
            }else{
                stck.push(s[i]);
            }
        }
        if(!stck.empty())return false;
        return true;
    }
    void generateParenthesis(int n,string s,int open,int close){
        if(open==0 && close ==0){
            ans.push_back(s);
            return ;
        }
        if(open>0){
            s.push_back('(');
            generateParenthesis(n,s,open-1,close);
            s.pop_back();
        }
        if(close>open){
            s.push_back(')');
            generateParenthesis(n,s,open,close-1);
            s.pop_back();
        }   
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int open = n , close = n;
         generateParenthesis(n,s,open,close);
        return ans;
    }
};