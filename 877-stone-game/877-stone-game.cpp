class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        priority_queue<int> pq;
        int n = piles.size();
        
        for(int i = 0; i < n; i++) {
            pq.push(piles[i]);
        }
        
        int alice = 0, bob = 0;
        bool flag = true;
        
        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            
            if(flag) {
                alice += top;
            }else {
                bob += top;
            }
            
            flag = !flag;
        }
        
        return alice > bob;
    }
};