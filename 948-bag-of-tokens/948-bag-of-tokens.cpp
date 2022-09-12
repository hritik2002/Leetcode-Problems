class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size() - 1;
        int score = 0;
        int ans = 0;
        
        while(left <= right) {
            if(power >= tokens[left]) {
                power -= tokens[left];
                score++;
                left++;
            }else {
                if(power > tokens[right]) {
                    right--;
                    power -= tokens[right--];
                    score++;
                }else {
                    if(score == 0) {
                        break;
                    }
                    power += tokens[right];
                    score--;
                    right--;
                }
            }
            
            ans = max(ans, score);
        }
        
        return ans;
    }
};