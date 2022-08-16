class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int size = s1.size();
        while(size--) {
            int top = s1.top();
            s2.push(top);
            s1.pop();
        }
        
        int top = s2.top();
        s2.pop();
        size = s2.size();
        
        while(size--) {
            int top = s2.top();
            s1.push(top);
            s2.pop();
        }
        
        return top;
    }
    
    int peek() {
        int size = s1.size();
        while(size--) {
            int top = s1.top();
            s2.push(top);
            s1.pop();
        }
        
        int top = s2.top();
        size = s2.size();
        
        while(size--) {
            int top = s2.top();
            s1.push(top);
            s2.pop();
        }
        
        return top;
    }
    
    bool empty() {
        return s1.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */