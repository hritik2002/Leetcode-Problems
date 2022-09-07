class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l , h , mid ;
        l = 0 ;
        h = nums.size()-1;
        while(l<=h){
            mid = (l+h)/2 ;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                l = mid+1 ;
            }else{
                h = mid-1 ;
            }
        }
        return -1;
    }
};