class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        
        if(a)
            maxHeap.push({a, 'a'});
        if(b)
            maxHeap.push({b, 'b'});
        if(c)
            maxHeap.push({c, 'c'});
        
        string ans = "";
        
        while(maxHeap.size() > 1) {
            auto first = maxHeap.top();
            maxHeap.pop();
            
            auto second = maxHeap.top();
            maxHeap.pop();
            
            if(first.first >= 2) {
                ans += first.second;
                ans += first.second;
                
                first.first -= 2;
            }else {
                ans += first.second;
                
                first.first--;
            }
            
            if(second.first >= 2 && second.first >= first.first) {
                ans += second.second;
                ans += second.second;
                
                second.first -= 2;
            }else {
                ans += second.second;
                
                second.first--;
            }
            
            if(first.first > 0) {
                maxHeap.push({first.first, first.second});
            }
            if(second.first > 0) {
                maxHeap.push({second.first, second.second});
            }
        }
        
        if(maxHeap.size() == 0) {
            return ans;
        }
        
        auto first = maxHeap.top();
        
        if(first.first >= 2) {
            ans += first.second;
            ans += first.second;

            first.first -= 2;
        }else {
            ans += first.second;

            first.first--;
        }
        
        return ans;
    }
};
