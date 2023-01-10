class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x = 0, y = 0;
        int i = 0;
        for(int j = 0; j < s2.length(); j++, i++) {
            if(s1[i] != s2[j]) {
                if(s1[i] == 'x') x++;
                else y++;
            }

        }
        
        if((x + y) % 2) {
            return -1;
        }
        int ans = (x + y) / 2;
        
        if(x % 2) {
            ans++;
        }
            
        return ans;
    }
};