class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stck;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stck.push(n-1);
        
        for(int i = n - 2; i>=0; i--){
            int top = stck.top();
            
            if(temperatures[top] > temperatures[i]){
                ans[i] = top - i;
            }else{
                while(stck.size() > 0 && temperatures[top] <= temperatures[i]){
                    stck.pop();
                    if(stck.size() > 0){
                        top = stck.top();
                    }else break;
                    
                }
                if(stck.size() == 0)
                    ans[i] = 0;
                else
                    ans[i] = top - i;
            }
            
            stck.push(i);
        }
        
        return ans;
    }
};