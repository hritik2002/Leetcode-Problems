class Solution {
public:
    void _merge(vector<int>&nums,int i,int j,int mid,int &ans){
        vector<int>temp;int k = 0;
        int l = i , r = mid + 1 ;
        while (l <= mid && r <= j){
            if ((long) nums[l] > (long) 2 * nums[r]){
                ans += (mid - l + 1);
                r++;
            }else {
                l++;
            }
        }
        int left = i , right = mid+1  ;
        while(left<=mid && right<=j){
            if(nums[left]>nums[right]){
                temp.push_back(nums[right]);
                right++;
            }
            else{
                temp.push_back(nums[left]);
                left++;
            }
        }       
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=j){
            temp.push_back(nums[right++]);
        }
        left = 0 ;
        for(;i<=j;i++){
            nums[i] = temp[left++];
        }
    }
    void _mergeSort(vector<int>&nums,int i,int j,int &ans){
        if(j-i<=0)return ;
        int mid = i + (j-i)/2;
        _mergeSort(nums,i,mid,ans);
        _mergeSort(nums,mid+1,j,ans);
        _merge(nums,i,j,mid,ans);
        return ;
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0 ;
        _mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};