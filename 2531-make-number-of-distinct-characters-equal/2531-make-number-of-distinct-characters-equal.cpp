class Solution {
public:
    bool isItPossible(string word1, string word2) {
        map<char, int> m1, m2;
        
        for(auto w : word1) m1[w]++;
        for(auto w : word2) m2[w]++;
        
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                char c1 = i + 'a', c2 = j + 'a';
                
                if(m1.count(c1) && m2.count(c2)) {
                    if(--m1[c1] == 0) m1.erase(c1);
                    if(--m2[c2] == 0) m2.erase(c2);
                    
                    // swap
                    m1[c2]++;
                    m2[c1]++;
                    
                    if(m1.size() == m2.size()) {
                        return true;
                    }
                    
                    m1[c1]++;
                    m2[c2]++;
                    
                    if(--m1[c2] == 0) m1.erase(c2);
                    if(--m2[c1] == 0) m2.erase(c1);
                }
            }
        }
        
        return false;
    }
};