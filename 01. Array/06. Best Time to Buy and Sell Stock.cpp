class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prefixMin(n);
        prefixMin[0] = prices[0];

        for (int i = 1; i < n; i++) {
            prefixMin[i] = min(prefixMin[i-1], prices[i]);
        }

        int profit = 0;
        for (int i = 0; i < n; i++) {
            profit = max(profit, prices[i] - prefixMin[i]);
        }

        return profit;
    }
};