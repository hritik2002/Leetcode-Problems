class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> left(n), right(n);
        int ind = -1;
        for(int i=n-1; i>=0; i--){
            left[i] = ind;
            if(s[i] == 'L') ind = i;
            else if(s[i] == 'R') ind = -1;
        }
        ind = -1;
        for(int i=0; i<n; i++){
            right[i] = ind;
            if(s[i] == 'R') ind = i;
            else if(s[i] == 'L') ind = -1;
        }
        // for(auto it: left) cout << it << " "; cout << endl;
        // for(auto it: right) cout << it << " "; cout << endl;
        for(int i=0; i<n; i++){
            if(s[i] == 'R' || s[i] == 'L') continue;
            if(left[i] == -1 && right[i] == -1) continue;
            if(left[i] == -1){
                s[i] = 'R';          
            }else if(right[i] == -1){
                s[i] = 'L';
            }else{
                if(left[i] - i == i - right[i]) continue;
                if(left[i] - i > i - right[i]){
                    s[i] = 'R';
                }else{
                    s[i] = 'L';
                }
            }
        }
        
        return s;
    }
};