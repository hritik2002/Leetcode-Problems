class Solution {
public:
    vector<int> ans;
    
    void getNumber(int n, int k, int currNum) {
        if(n == 0) {
            ans.push_back(currNum);
            
            return;
        }
        
        for(int i = 0; i <= 9; i++) {
            if(abs(currNum%10 - i) == k) {
                getNumber(n - 1, k, currNum*10 + i);
            }
        }
        
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        
        for(int i = 1; i <= 9; i++) {
            getNumber(n - 1, k, i);
        }
        
        return ans;
    }
};