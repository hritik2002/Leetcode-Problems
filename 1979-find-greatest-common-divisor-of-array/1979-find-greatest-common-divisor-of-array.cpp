class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int first = nums[0] , second = nums[nums.size()-1];
        while(second!=0){
            int temp = first ;
            first = second ;
            second = temp%second;
        }
        return first;
    }
};