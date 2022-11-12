class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length()==0){
            return (s.length()==0);
        }
        vector<vector<bool>> dp(s.length()+1,vector<bool> (p.length()+1, false));
        
        dp[s.length()][p.length()] = true;
        
        for(int i = s.length(); i >= 0; i--) {
            for(int j = p.length() - 1; j >= 0; j--) {
                if(i==s.length())
                    dp[i][j] = (p[j]=='*' && dp[i][j + 1]);
                else if(i<s.length() &&  (p[j]==s[i] || p[j]=='?'))
                {
                   dp[i][j]=  dp[i+1][j+1];
                }
                else if(p[j]=='*')
                {
                    dp[i][j]= (dp[i][j + 1] || dp[i + 1][j]);
                }
                else
                    dp[i][j]= false;
                }
        }
        
        return  dp[0][0];
    }  
};