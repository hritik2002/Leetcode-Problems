class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0 ;
        map<int,int>hash ;
        for(int i=0  ; i<nums.size();i++ ){
            if(hash[nums[i]])hash[nums[i]]++;
            else hash[nums[i]]=1;
        }
        for(auto val : nums){
            int first = val ;
            
            if(first==k-first && hash[first]>=2){
                cout<<first<<"   "<<hash[first]<<"  "<<count<<endl;
                hash[first] -= 2 ;
                count++;
            }else if(first!=k-first&&hash[k-first]>0 && hash[first]>0){
                cout<<first<<"   "<<hash[first]<<"  "<<count<<endl;
                hash[first]--;
                hash[k-first]--;
                count++;
            }
        }
        return count;
    }
};