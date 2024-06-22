// 121. Best Time to Buy and Sell Stock (EASY)
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

//Brute: Check for each day with every other day
//Gives TLE on large inputs
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;

        for(int i=0;i<n;i++){
            int buy = prices[i];
            for(int j=i+1;j<n;j++){
                int sell = prices[j];
                int profit = sell - buy;
                if(profit < 0) profit = 0;
                maxProfit = max(profit, maxProfit);
            }
        }

        return maxProfit;
    }
};


//Better: 
//Two pointers for buy and sell, 
//keep buy at the smallest price found yet and update sell to next price at each iteration
//check with maxProfit at each iteration
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), i=2;
        if(n <= 1) return 0;

        int maxProfit = 0, profit;
        int buy = prices[0], sell = prices[1];

        while(i <= n){
            profit = sell - buy;
            maxProfit = max(profit, maxProfit);
            if(buy > sell){
                buy = sell;
            }
            sell = prices[i];
            i++;
        }

        maxProfit = max(profit, maxProfit);
        return maxProfit;
    }
};


//Optimal: Keep track of the smallest and check maxProfit at each iteration
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int smallest = prices[0];
        int maxProfit = 0;

        for(int i=1;i<n;i++){
            int profit = prices[i] - smallest;
            maxProfit = max(maxProfit, profit);
            smallest = min(smallest, prices[i]);
        }

        return maxProfit;
    }
};
