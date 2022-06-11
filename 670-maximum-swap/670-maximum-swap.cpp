class Solution {
public:
    int maximumSwap(int num) {
        long long ans = 0 ;
        string s = to_string(num);
        int n = s.length();
        int _max = INT_MIN ,  _maxI = -1;
        for(int i=0 ; i<n ; i++){
            if(s[i]<s[i+1]){
                _max = max(_max,s[i+1]-48);
                if(_max==s[i+1]-48)_maxI=i+1;
                
            }
            if(_max==s[i+1]-48)_maxI=i+1;
        }
        if(_maxI==-1)return num;
        int _min = INT_MAX , _minI = _maxI-1;
        for(int i=_maxI-1;i>=0;i--){
            
            if(s[i]-48<_max){
                _minI = i ;
            }
        }
        
        swap(s[_minI],s[_maxI]);
        for(int i=0 ;i <s.length();i++){
            ans = ans*10 + s[i]-48;
        }
        return ans;
    }
};