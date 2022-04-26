class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour==12){
            hour = 0 ;
        }
        double hr = (double)hour ;
        hr += (double)minutes/60 ;
        double angle = abs(hr - (double)minutes/5)*30 ;
        cout<<abs(hr - (double)minutes/5)<<endl;
        return min(360-angle,angle);
    }
};