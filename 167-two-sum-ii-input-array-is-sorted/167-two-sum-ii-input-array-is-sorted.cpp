class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0 , j = numbers.size()-1;
        vector<int>ans(2,0);
        while(i<j){
            int sum = numbers[i] + numbers[j];
            if(sum>target)j--;
            else if(sum<target)i++;
            else {
                ans[0]=i+1;
                ans[1]=j+1;
                return ans;
            }
        }
        return ans;
    }
};