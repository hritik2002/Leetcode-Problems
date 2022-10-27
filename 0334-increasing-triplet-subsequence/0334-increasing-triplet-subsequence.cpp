class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, mid = INT_MAX;
        
        for(auto x : nums) {
            if(x > mid) {
                return true;
            }
            
            if(x > left && x < mid) {
                mid = x;
            }else if(x < left) {
                left = x;
            }
        }
        
        return false;
    }
};