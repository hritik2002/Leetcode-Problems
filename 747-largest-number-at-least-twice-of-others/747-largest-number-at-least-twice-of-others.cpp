class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int max1 = INT_MIN , max2 = INT_MIN , i1=-1 , i2 =-1 ;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]>=max1){
                max2 = max1;
                i2 = i1 ;
                i1 = i;
                max1 = nums[i];
            }else if(nums[i]>=max2){
                max2 = nums[i];
                i2 = i;
            }
        }
        
        if(max2==INT_MIN)return -1;
        if(max1>=2*max2)return i1;
        return -1;
    }
};