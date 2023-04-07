class Solution {
public:
    bool isPossible(long long travelTime, vector<int>& time, int totalTrips) {
        long long cnt = 0;
        for(int i = 0; i < time.size(); i++) {
            cnt += travelTime / time[i];
            
            if(cnt >= totalTrips) {
                return true;
            }
        }
        
        return cnt >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans = 10000000000000000, low = 1, high = 10000000000000000;
        
        while(low <= high) {
            long long mid = high - (high - low) / 2;
            
            if(isPossible(mid, time, totalTrips)) {
                ans = min(ans, mid);
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};