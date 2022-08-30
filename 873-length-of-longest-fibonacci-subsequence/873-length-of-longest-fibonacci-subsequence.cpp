class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> st;
        int n = arr.size();
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            st.insert(arr[i]);
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long a = arr[i], b = arr[j];
                long long c = a + b;
                int count = 0;
                
                while(st.count(c)) {
                    count++;
                    a = b;
                    b = c;
                    c = a + b;
                }
                
                ans = max(ans, count);
            }
        }
        
        return ans == 0? 0: ans + 2;
    }
};