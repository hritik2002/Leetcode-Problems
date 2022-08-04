class MyCalendar {
public:
     map<int, int> events;
    
    MyCalendar() {   
    }
    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        int sum = 0;
        
        for(auto event : events){
            sum += event.second;
            
            if(sum > 1){
                events[start]--;
                events[end]++;
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */