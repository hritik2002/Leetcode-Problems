class Solution {
public:

    bool isValid(string s){
        // return true;
        int n = s.length();
        stack<char>st;
        for(auto i:s){
            if(i=='(' or i=='{' or i=='[') st.push(i);
            else{
               if(st.empty() or (st.top()=='(' and i!=')') 
                  or (st.top()=='{' and i!='}') 
                  or (st.top()=='[' and i!=']')) return false;
                st.pop();  
            }
        }
        if(!st.empty())return false;
        return true;
    }
    
};