class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0 ;
        for(int i=0 ; i<nums.size();i++){
            string temp = nums[i];
            for(int j=0 ; j<nums.size();j++){
                if(i==j)continue;
                if(temp+nums[j]==target){
                    count++;
                    temp = nums[i];
                }
            }
        }
        return count ;
    }
};