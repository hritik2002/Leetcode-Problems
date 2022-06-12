class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = accumulate(begin(nums), end(nums), 0);
        long long target = sum -x ;
        if(target==0)return nums.size();
        else if(target<0)return -1;
        int n = nums.size();
        sum = 0;
        int left= 0 , res = -1;
        for(int i=0 ;i<nums.size();i++){
            sum += nums[i];
            while(sum>target){
                sum -= nums[left++];
                if(left>nums.size())
                     break;
            }
            
            if(sum==target){
                cout<<sum<<endl;
                res = max(res,i-left+1);
            }
        }
      
        return res==-1?res:n-res;
    }
};