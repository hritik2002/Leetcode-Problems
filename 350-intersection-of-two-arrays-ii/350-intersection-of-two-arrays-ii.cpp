class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> intersectedNumber;
        int n = nums1.size();
        
        for(int i = 0; i < n; i++){
            intersectedNumber[nums1[i]]++;
        }
        
        vector<int> ans;
        
        n = nums2.size();
        
        for(int i = 0; i < n; i++){
            if(intersectedNumber[nums2[i]]){
                ans.push_back(nums2[i]);
                intersectedNumber[nums2[i]]--;
            }
        }
        
        return ans;
    }
};