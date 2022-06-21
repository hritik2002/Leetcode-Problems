class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int m =potions.size() ;
        int n = spells.size();
        vector<int>ans;
        for(int i=0 ; i<n ;i++){
            int num = spells[i];
            int l = 0 , h = m-1;
            int res = m ;
            while(l<=h){
                int mid = l + (h-l)/2;
                if(potions[mid]*1L*num>=success){
                    h = mid - 1 ;
                    res = mid ;
                }else l = mid + 1;
            }
            ans.push_back(m-res);
        }
        return ans;
    }
};