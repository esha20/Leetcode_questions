class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min=prices[0],Maxprofit=0, profit=0;
        for(int i=0;i<prices.size();i++)
        {
            if(min>prices[i])
            {
                min=prices[i];
            }
            profit = prices[i]-min;
            if(profit>Maxprofit)
            {
                Maxprofit= profit;
            }
        }
        return Maxprofit;
    }
};