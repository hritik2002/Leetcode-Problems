class Solution {
public:
    void getCombinationSum3(int k,int n,int &sum,vector<int>&arr,vector<vector<int>>&ans,int currNum){
        if(k==0){
            if(sum==n){
                ans.push_back(arr);
            }
            return;
        }
        if(sum>n)return;
        for(int i=currNum;i<=9;i++){
            sum += i ;
            arr.push_back(i);
            getCombinationSum3(k-1,n,sum,arr,ans,i+1);
            arr.pop_back();
            sum -= i ;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        if(n==1)return ans;
        vector<int>arr;
        int sum = 0;
        getCombinationSum3(k,n,sum,arr,ans,1);
        return ans;
    }
};