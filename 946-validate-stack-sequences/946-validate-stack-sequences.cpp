class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), m = popped.size();
        int i = 0, j = 0;
        stack<int> st;
        
        while(i < n && j < n) {
            if(i < n) {
                st.push(pushed[i]);
                i++;
            }
            
            while(j < m && st.size() > 0 && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        
        if(st.size() == 0 && i >= n && j >= m) {
            return true;
        }
        
        return false;
    }
};