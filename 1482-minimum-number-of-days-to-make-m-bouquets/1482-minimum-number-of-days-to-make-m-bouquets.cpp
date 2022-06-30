class Solution {
public:
    bool isValid(vector<int>& bloomDay,int m,int k,int day){
        if(m*k>day)return false; 
        int bloomed_flowers = 0, bouquets_ready = 0 ;
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day){
                bloomed_flowers++;
            }else{
                bloomed_flowers = 0 ;
            }
            if(bloomed_flowers>=k){
                bloomed_flowers = 0 ;
                bouquets_ready++;
            }
            // cout<<bouquets_ready<<endl;
            if(bouquets_ready>=m)return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        /*
            steps to solve this problem:
                > Take a maximum possible number, which satisfies the answer.
                > Run binary search and find the minimum number which satisfies the condition.
                > The question represents a monotonic function.
        */
        int low = 1 , high = *max_element(bloomDay.begin(),bloomDay.end());
        if(m*k>high)return -1;
        int ans = INT_MAX ;
        while(low<=high){
            int mid = low + (high-low)/2 ;
            if(isValid(bloomDay,m,k,mid)){
                ans = min(ans,mid);
                high = mid - 1 ;
            }else low = mid + 1 ;
        }
        return ans<INT_MAX ? ans : -1 ;
    }
};