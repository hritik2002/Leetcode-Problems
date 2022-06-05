class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0 ;
        long long k = 1 ;
        for(int i=1 ; i<=32 ; i++){
            int count = 0 ;
            for(int j=0 ; j<nums.size();j++){
                if((nums[j]&k)==k){
                    count++;
                }
            }
            if(count%3==1){
                res = res | k ;
            }
            k <<= 1 ;
        }
        return res;
    }
};