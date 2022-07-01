class Solution {
public:
    bool check_condition(vector<int>&piles,int curr_speed , int hour){
        int count = 0 ;
        int n = piles.size();
        for(int i=0;i<n;i++){
            count += piles[i]/curr_speed;
            if(piles[i]%curr_speed)count++;
        }
        if(count<=hour)return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int hour) {
        /*
            Note:
                > It is a monotonic increasing function.
                > Find the min. point from which the function starts satisfying all the condition.
        */
        int low_eating_speed = 1 , high_eating_speed = INT_MAX ;
        int ans = INT_MAX;
        while(low_eating_speed<=high_eating_speed){
            int curr_eating_speed = low_eating_speed + (high_eating_speed-low_eating_speed)/2;
            if(check_condition(piles,curr_eating_speed,hour)){
                ans = min(ans,curr_eating_speed);
                high_eating_speed = curr_eating_speed - 1 ;
            }else low_eating_speed = curr_eating_speed + 1 ;
        }
        return ans;
    }
};