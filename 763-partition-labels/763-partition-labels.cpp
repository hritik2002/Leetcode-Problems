class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int>freq;
        for(int i=0 ; i<s.length();i++){
            if(freq.count(s[i])){
                freq[s[i]] = max(freq[s[i]],i);
            }else {
                freq[s[i]] = i ;
            }
        }
        vector<int>ans;
        int len = 0 ;
        int end = freq[s[0]] ;
        for(int i=0 ; i<s.length(); i++){
            end = max(end,freq[s[i]]);
            if(i==end){
                len++;
                ans.push_back(len);
                len = 0 ;
            }else{
                len++;
            }
            
        }
        return ans;
    }
};