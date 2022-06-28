class Solution {
public:
    void getLetterCasePermutation(string &s,int index,string &perStr,vector<string>&res,int size){
        if(index==size){
            res.push_back(perStr);
            return ;
        }
        if(s[index]>=48 && s[index]<=59){
            perStr.push_back(s[index]);
            getLetterCasePermutation(s,index+1,perStr,res,size);
            perStr.pop_back();
        }else{
            perStr.push_back(s[index]);
            getLetterCasePermutation(s,index+1,perStr,res,size);
            perStr.pop_back();
            if(s[index]==toupper(s[index])){
                perStr.push_back(tolower(s[index]));
                getLetterCasePermutation(s,index+1,perStr,res,size);
            }else{
                perStr.push_back(toupper(s[index]));
                getLetterCasePermutation(s,index+1,perStr,res,size);
            }
            perStr.pop_back();
            
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        string perStr;
        int index = 0;
        getLetterCasePermutation(s,index,perStr,res,s.length());
        return res;
    }
};