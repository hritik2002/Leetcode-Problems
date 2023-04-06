class Solution {
public:
    bool possible(long long candySize, vector<int> &candies, long long k) {
        long long cnt = 0;
        long long rem = 0;
        
        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] >= candySize) {
                cnt += (candies[i]) / candySize;
            }
            
            if(cnt >= k) {
                return true;
            }
        }
        
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long ans = 0;
        long long low = 1, high = 1e7 + 1;
        sort(candies.begin(), candies.end());
        
        for(auto c : candies) {
            cout<<c<<" ";
        }
        cout<<endl;
        
        while(low <= high) {
            long long mid = high - (high - low) / 2;
            if(possible(mid, candies, k)) {
                ans = max(ans, mid);
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};