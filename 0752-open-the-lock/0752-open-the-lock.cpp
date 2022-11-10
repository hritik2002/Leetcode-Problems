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
                if(s[i] == '9') {
                    s[i] = '0';
                }else 
                    s[i]++;
                
                if(!st.count(s)) {
                    q.push({s, p.second + 1});
                    st.insert(s);
                }
                if(s[i] == '0') {
                    s[i] = '9';
                }else
                    s[i]--;
            }
            for(int i = 0; i < 4; i++) {
                if(s[i] == '0') {
                    s[i] = '9';
                }else
                    s[i]--;
                
                if(!st.count(s)) {
                    q.push({s, p.second + 1});
                    st.insert(s);
                }
                if(s[i] == '9') {
                    s[i] = '0';
                }else
                    s[i]++;
            }
        }
        
        return -1;
    }
};