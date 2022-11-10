class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q;
        set<string> st;
        
        for(auto d : deadends) {
            st.insert(d);
        }
        
        if(st.count("0000"))return -1;
        
        q.push({"0000", 0});
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            string s = p.first;
            
            if(s == target) {
                return p.second;
            }
            
            for(int i = 0; i < 4; i++) {
                int c = s[i] - '0';
                s[i] = (c + 1) % 10 + '0';
                
                if(!st.count(s)) {
                    q.push({s, p.second + 1});
                    st.insert(s);
                }
                
                s[i] = (c - 1 + 10) % 10 + '0';
                if(!st.count(s)) {
                    q.push({s, p.second + 1});
                    st.insert(s);
                }
                
                s[i] = c + '0';
            }
        }
        
        return -1;
    }
};