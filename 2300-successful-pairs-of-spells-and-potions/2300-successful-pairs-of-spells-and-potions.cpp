class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size() , m = potions.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int num = spells[i];
            int l=0,h=m-1, res = m ;
            while(l<=h){
                int mid = l + (h-l)/2;
                if(1L*num*potions[mid]>=success){
                    res = mid ;
                    h = mid-1;
                }else l = mid+1;
            }
            ans.push_back(m-res);
        }
        return ans;
    }
};