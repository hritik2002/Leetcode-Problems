class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<vector<int>> AA(2);
        vector<vector<int>> BB(2);
        
        for(auto x : nums) {
            if(x % 2 == 0) {
                AA[0].push_back(x);
            }else AA[1].push_back(x);
        }
        for(auto x : target) {
            if(x % 2 == 0) {
                BB[0].push_back(x);
            }else BB[1].push_back(x);
        }
        
        sort(AA[0].begin(), AA[0].end());
        sort(AA[1].begin(), AA[1].end());
        sort(BB[0].begin(), BB[0].end());
        sort(BB[1].begin(), BB[1].end());
        long long sum = 0;
        
        for(int i = 0; i < AA[0].size(); i++) {
            sum += abs(AA[0][i] - BB[0][i]) / 2;
        }
        for(int i = 0; i < AA[1].size(); i++) {
            sum += abs(AA[1][i] - BB[1][i]) / 2;
        }
        
        return sum / 2;
    }
};