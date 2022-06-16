class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count = 0 ;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j){
            if(i!=j && people[i]+people[j]<=limit){
                count++;
                i++;
                j--;
            }else{
                count++;
                j--;
            }
        }
        return count;
    }
};