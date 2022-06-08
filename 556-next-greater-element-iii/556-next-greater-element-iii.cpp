class Solution {
public:
    
    int nextGreaterElement(int n) {
        if(n<=11)return -1;
        
        string s = to_string(n);
       int index = 0 ;
        for(int i=s.length()-1;i>=1;i--){
            if(s[i]>s[i-1]){
                index = i-1;
                break;
            }
        }
        for(int i=s.length()-1 ; i>=0 ; i--){
            if(s[i] > s[index]){
                char temp = s[i];
                s[i] = s[index] ;
                s[index] = temp ;
                break;
            }
        }
        int start = index + 1 , end = s.length()-1;
        while(start<=end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp ;
            start++;
            end--;
        }
        long long ans= 0;
        for(int i=0 ; i<s.length();i++){
           
            ans = ans*10 + s[i]-48 ;
        }
        if(ans>INT_MAX || ans<=n)return -1;
        return ans;
        
    }
};