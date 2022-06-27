class Solution {
public:
    vector<string>ans;
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