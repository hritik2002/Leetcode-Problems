class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int first = nums[0] , second = nums[nums.size()-1];
        while(first!=second){
            if(first>second)first-=second;
            else second -= first ;
        }
        return first;
    }
};