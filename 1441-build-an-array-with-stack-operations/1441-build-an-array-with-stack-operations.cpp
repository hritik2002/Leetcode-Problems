class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0, len = target.size();
        int start = 1;
        
        for( ; i < len && n > 0 ; start++, n--){
            if(start == target[i]){
                ans.push_back("Push");
                i++;
            }else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            
        }
        
        return ans;
    }
};