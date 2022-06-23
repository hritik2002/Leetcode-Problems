class Solution {
public:
    void sortColors(vector<int>& nums) {
        // count sort;
        vector<int>count(3,0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        int k = 0;
        for(int i=0;i<3;i++){
            while(count[i]--){
                nums[k++] = i ;
            }
        }
    }
};