class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> powers;
        vector<int> ans;
        int num = n;
        int cnt = 2, i = 0;
        
        while(num) {
            if(num & 1) {
                powers.push_back(pow(cnt, i));
            }
            
            i++;
            num = num >> 1;
        }
        
        for(auto query : queries) {
            int start = query[0];
            int end = query[1];
            long long prod = 1;
            
            while(start <= end) {
                prod = (prod * powers[start])%mod;
                start++;
            }
            
            ans.push_back(prod);
        }
        
        return ans;
    }
};