// 121. Best Time to Buy and Sell Stock (EASY)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

//Space: O(1), Time: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0], sell=prices[0], max_profit=0;
        if(prices.size()==0) return 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<buy){
                buy=prices[i];
                sell=prices[i];
            }else if(prices[i]>sell){
                sell=prices[i];
                max_profit=max(max_profit, sell-buy);
            }
        }
        return max_profit;
    }
};
