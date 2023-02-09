class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans, curr;
        
        for(auto num : arr) {
            set<int> st = {num};
            
            for(auto c : curr) st.insert(num | c);
            curr = st;
            for(auto c : curr) ans.insert(c);
        }
        
        return ans.size();
    }
};