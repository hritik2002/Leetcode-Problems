class Solution {
public:
    string getHint(string secret, string guess) {
        int i = 0, j = 0, n = secret.length(), m = guess.length();
        vector<int> sArr(10, 0), gArr(10, 0);
        int cow = 0, bull = 0;
        
        while(i < n && j < m) {
            if(secret[i] == guess[j]) {
                bull++;
            }else {
                sArr[secret[i] - '0']++;
                gArr[guess[i] - '0']++;
            }
            
            i++;
            j++;
        }
        
        for(int i = 0; i < 10; i++) {
            cow += min(sArr[i], gArr[i]);
        }
        
        return to_string(bull) + 'A' + to_string(cow) + 'B';
    }
};