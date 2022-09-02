class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr = 
        {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
         "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
         "..-","...-",".--","-..-","-.--","--.."
        };

    set<string> st;

    int n = words.size();
    
    for(int i = 0; i < n; i++) {
        int len = words[i].length();
        string pattern = "";
        
        for(int j = 0; j < len; j++) {
            pattern += arr[words[i][j] - 'a'];
        }
        
        st.insert(pattern);
    }
    
    return st.size();
    }
};