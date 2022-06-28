class Solution {
public:
    void getWays(vector<int>&nums,int target,int &count,int sum,int index,int size){
        if(index==size){
            if(sum==target){
                count++;
            }
            return; 
        }  
        sum += nums[index];     // add current element from  sum
        getWays(nums,target,count,sum,index+1,size);
        sum -= nums[index];     // remove current element from sum
        sum -= nums[index];    // subtract current element from  sum
        getWays(nums,target,count,sum,index+1,size);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0,sum=0 ;
        int n = nums.size();
        getWays(nums,target,count,sum,0,n);
        return count;
    }
};