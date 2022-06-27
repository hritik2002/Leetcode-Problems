class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string>ans;
        string s,temp;
        for(int i=0;i<n;i++)s+= '0',temp+='1';
        ans = generateAns(n);
        vector<int>res;
        for(int i=0;i<ans.size();i++){
            res.push_back(getNumber(ans[i]));
        }
        return res;
    }
    vector<string> generateAns(int n){
        vector<string>res;
        if(n==1){
            res.push_back("0");
            res.push_back("1");
            return res;
        }
        vector<string>ans = generateAns(n-1);
        for(int i=0;i<ans.size();i++){
            res.push_back('0'+ans[i]);
        }
        for(int i=ans.size()-1;i>=0;i--){
            res.push_back('1'+ans[i]);
        }
        return res;
    }
    int getNumber(string s){
        int ans = 0 ;
        int n = s.length();
        for(int i=s.length()-1 ; i>=0 ; i--){
            if(s[i]=='1'){
                ans = ans + pow(2,n-i-1);
            }
        }
        return ans;
    }
};