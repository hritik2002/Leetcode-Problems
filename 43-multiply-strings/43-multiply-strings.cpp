class Solution {
public:
    string multiply(string num1, string num2) {
        int last_col = num1.length()+num2.length();
        int factor = 0 ;
        vector<int>ans(last_col,0);
        for(int i=num1.length()-1;i>=0;i--){
            
            int k = last_col -factor-1 ;
            vector<int>temp(last_col,0);
            int carry = 0 , j;
            for(j=num2.length()-1;j>=0;j--){
                int mult = ((int)num1[i]-48)*((int)num2[j]-48) + carry;
                int rem = mult%10;
                temp[k--] = rem ;
                carry = mult/10 ;
            }
            if(carry){
                temp[k--] = carry ;
            }
            factor++;
            carry = 0 ;
            for(int j=last_col-1;j>=0;j--){
                int sum =  (temp[j] + carry) + ans[j];
                ans[j] = sum%10;
                carry = sum / 10;
            }
        }
        int i = 0 ;
        while(i<last_col && !ans[i])i++;
        string res = "";
        
        for( ; i<ans.size();i++){
            res +=  to_string(ans[i]) ;
        }
        if(res.length()==0)return "0";
        return res;
        
        
    }
    
};