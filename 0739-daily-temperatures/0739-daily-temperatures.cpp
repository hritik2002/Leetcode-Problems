class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> temperatureStack;     // {value, index}
        int size = temperatures.size();
        vector<int> ans(size, 0);
        
        for(int i = size - 1; i >= 0; i--) {
            int currentElement = temperatures[i];
            
            if(temperatureStack.size()) {
                auto top = temperatureStack.top();
                
                while(temperatureStack.size() && top.first <= currentElement) {
                    temperatureStack.pop();
                    
                    if(temperatureStack.size())
                        top = temperatureStack.top();
                }
                
                if(top.first > currentElement) {
                    ans[i] = top.second - i;
                }
            }
            
            temperatureStack.push({currentElement, i});
        }
        
        return ans;
    }
};