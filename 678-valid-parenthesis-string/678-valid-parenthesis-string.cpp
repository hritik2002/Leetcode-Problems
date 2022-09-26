class Solution {
public:
    bool checkValidString(string s) {
        int lower = 0, upper = 0;
        
        for(auto ch : s) {
            if(ch == '(') {
                
                lower++;
                upper++;
            }else if(ch == ')') {
                lower--;
                upper--;
            }else 
                lower--, upper++;
            
            if(upper < 0) {
                return false;
            }
            
            lower = max(lower, 0);
        }
        
        return lower == 0;
    }
};