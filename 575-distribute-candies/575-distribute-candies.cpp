class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> st;
        int cntUnique = 0, half = candyType.size() / 2;
        
        for(auto type : candyType) {
            if(!st.count(type)) {
                cntUnique++;
                st.insert(type);
            }
        }
        
        if(cntUnique > half) {
            return half;
        }
        
        return cntUnique;
    }
};