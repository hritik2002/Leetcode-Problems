class StockSpanner {
public:
    vector<pair<int, pair<int, int>>> stocks;      // current value, 
    int size;
    
    StockSpanner() {
        size = 0;
    }
    
    int next(int price) {
        int days = 1;
        int end = size - 1;
        int maxStock = 0;
        
        while(end >= 0 && stocks[end].first <= price) {
//             if(stocks[end].second.first > price) {
//                 days += stocks[end].second.second + 1;
//                 maxStock = max(maxStock, stocks[end].second.first);
//                 break;
//             }
            
            end--;
            days++;
        }
        
        if(end >= 0) {
            maxStock = max(maxStock, stocks[end].second.first);
            stocks.push_back({price, {maxStock, days}});
        }else {
            stocks.push_back({price, {INT_MAX, days + 1}});
        }
        
        size++;
        
        return days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */