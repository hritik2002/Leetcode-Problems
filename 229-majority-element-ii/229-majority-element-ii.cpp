class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1 = 0 , val2 = 0 , count1 = 0 , count2 = 0 ;
        int n = nums.size();
        for(auto x:nums){
            if(x==val1)count1++,val1=x;
            else if(x==val2)count2++,val2=x;
            else if(count2==0)count2=1,val2=x;
            else if(count1==0)count1=1,val1=x;
            else count1--,count2--;
        }
        count1=0,count2=0;
        for(auto x:nums){
            if(x==val1)count1++;
            else if(x==val2)count2++;
        }
        vector<int>ans;
        if(count1>n/3)ans.push_back(val1);
        if(count2>n/3)ans.push_back(val2);
        return ans;
    }
};