class Solution {
public:
    bool check_if_value_satisfies(vector<int>&nums,int value,int threshold){
        int sum = 0 ;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i]/value ;
            if(nums[i]%value)sum++;
        }
        if(sum<=threshold)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        /*
            Note : 
                > Monotonic increasing function
                > Find the minimum value for which the condition is satisfied.
                > Condition : Sum of the division(as mentioned in question) should be less than threshold.
        */
        int low = 1, high = 1000000;
        int ans = high ;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check_if_value_satisfies(nums,mid,threshold)){
                ans = min(ans,mid);
                high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};