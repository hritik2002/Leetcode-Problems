class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        bool flag = false ;
        for(int i=0 ;i<nums.size();i++)if(nums[i]>=0){flag=true;break;}
        if(flag){
            int sum = 0 ,max_sum=0;
        for(int i=0 ; i<nums.size(); i++){
            sum += nums[i];
            max_sum = max(max_sum,sum);
            if(sum<0)sum = 0 ;
        }
        return max_sum;
            
        }
        
        
        else {
int sum = nums[0] ,max_sum=nums[0];
        for(int i=1 ; i<nums.size(); i++){
            sum = max(nums[i],sum+nums[i]);
            max_sum = max(max_sum,sum);
           
        }
        return max_sum;
        
        }
        
        
    }
};