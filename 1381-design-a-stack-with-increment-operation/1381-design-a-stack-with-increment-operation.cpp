class CustomStack {
public:
    vector<int> arr;
    int top;
    int size;
    CustomStack(int maxSize) {
        this->arr.resize(maxSize,0);
        this->size = maxSize;
        this->top = -1;
    }
    
    void push(int x) {
        if(this->top < this->size - 1){
            this->arr[this->top+1] = x;
            this->top++;
        }
    }
    
    int pop() {
        if(top < 0) return -1;
        
        int top_element = arr[top];
        top--;
        
        return top_element;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i <= top; i++){
            if(i < k)
                arr[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */