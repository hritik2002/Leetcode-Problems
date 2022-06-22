class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0 , n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1)count++;
        }
        int bad = 0 ;
        for(int i=0;i<count;i++){
            if(nums[i]!=1)bad++;
        }
        int ans = bad;
        for(int i=0,j=count%n ; i<n ; j=(j+1)%n,i++){
            if(nums[i]!=1)bad--;
            if(nums[j]!=1)bad++;
            ans = min(ans,bad);
        }
        return ans;
    }
};