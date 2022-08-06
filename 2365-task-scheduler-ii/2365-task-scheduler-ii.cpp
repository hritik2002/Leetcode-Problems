class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long count = 0;
        int n = tasks.size();
        map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            if(mp.count(tasks[i])){
                int diff = count - mp[tasks[i]] - 1;
                if(space > diff){
                    count += space - diff;
                }
            }
            mp[tasks[i]] = count;
            count++;
        }
        
        return count;
    }
};