class BrowserHistory {
public:
    vector<string> history;
    int start = -1, end = -1;
    int curr = -1;
    
    BrowserHistory(string homepage) {
        history.resize(500);
        history[0] = homepage;
        start = 0;
        curr = 0;
        end = 1;
    }
    
    void visit(string url) {
        history[++curr] = url;
        end = curr + 1;
    }
    
    string back(int steps) {
        if(curr - steps < 0) {
            curr = 0;
        }else {
            curr -= steps;
        }
        
        

        return history[curr];
    }
    
    string forward(int steps) {
        if(curr + steps >= end) {
            curr = end - 1;
            
            return history[curr];
        }
        
        curr += steps;
        
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

// l
// g