class Solution {
public:
    void helper(string digits,int n , map<int,string>&store,int index,vector<string>&ans,string res){
        if(index==n){
            ans.push_back(res);
            return;
        }
        int num = digits[index]-48;
        int len = store[num].length();
        for(int i=0 ; i<len ; i++){
            helper(digits,n,store,index+1,ans,res+store[num][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int,string> store  ;
        store[2] = "abc";
        store[3] = "def";
        store[4] = "ghi";
        store[5] = "jkl";
        store[6] = "mno";
        store[7] = "pqrs";
        store[8] = "tuv";
        store[9] = "wxyz";
        vector<string>ans;
        int len = digits.length();
        string str = "";
        if(digits.length()>=1)
        helper(digits,len,store,0,ans,str);
        return ans;
        
    }
};