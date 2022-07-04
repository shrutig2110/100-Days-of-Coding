// USING PEAK VALLEY APPROACH 
// For every peak value we take diff of it from the valley element and add it to profit
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        for(int i =1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
            {
                profit += prices[i] - prices[i-1];
            }
        }
        return profit;
    }
};