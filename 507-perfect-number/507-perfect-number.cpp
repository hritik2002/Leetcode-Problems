class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int>res(1,1);
        int upper=num;
        for(int i=2;i<upper;i++) if(num%i==0) res.push_back(i), res.push_back(num/i), upper=num/i;
        
        int sum=0;
        for(auto i:res) sum+=i;
        
        return sum==num && num!=1;
    }
};