class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0 , __max = INT_MIN , __min = INT_MAX  ;
        for(int i=0 ; i<arr.size();i++){
            __max = max(__max,arr[i]);
            if(__max==i){
                ans++;
            }
        }
  
        return ans;
    }
};