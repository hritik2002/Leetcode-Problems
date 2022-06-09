class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int   max1 = INT_MIN , max2 = INT_MIN , max3 = INT_MIN;
        int  min1 = INT_MAX, min2 = INT_MAX;
        for(int i=0 ; i<nums.size();i++){
            if(min1>=nums[i]){
                min2 = min1 ;
                min1 = nums[i];
            }else if(min2>=nums[i])min2 = nums[i];
             if(max1<=nums[i]){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }else if(max2<=nums[i]){
                max3 = max2;
                max2 = nums[i];
            }else if(max3<=nums[i])max3 = nums[i];
        }
        return max(max1*max2*max3,max1*min1*min2);
    }
};