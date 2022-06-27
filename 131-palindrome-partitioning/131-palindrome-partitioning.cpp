class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        if(s.length()==0)return ans;
        vector<string>path;
        int index = 0 ;
        dfs(s,index,path,ans);
        return ans;
    }
    void dfs(string s,int index,vector<string>&path,vector<vector<string>>&ans){
        if(index==s.length()){
            ans.push_back(path);
            return ;
        }
        int n = s.length();
        for(int i=index ; i<n;i++){
            if(pallindrome(s,index,i)){
                string temp = "";
                int j = index ;
                while(j<=i){
                    temp += s[j++];
                }
                path.push_back(temp);
                dfs(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    bool pallindrome(string s,int start,int end){
        while(start<=end)if(s[start++]!=s[end--])return false;
        return true;
    }
};

// Time complexity of this approach is 2^n as each element as two option of getting added or not getting added.