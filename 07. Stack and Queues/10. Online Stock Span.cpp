class StockSpanner {
public:
    vector<pair<int,int>> arr;
    StockSpanner() {
    }
    
    int next(int price) {
        if (arr.empty()) {
            arr.push_back({price, 1});
            return 1;
        }

        int ans = 1;

        while (!arr.empty() && arr.back().first <= price) {
            ans += arr.back().second;
            arr.pop_back();
        }
        arr.push_back({price, ans});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */