/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    //tech dose solution On time O1 space
    //PEAK_VALLEY APPROACH

    int maxProfit(vector<int> &prices)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = prices.size();
        int diff = 0;
        for (int i = 1; i < n; ++i)
        {
            if (prices[i] > prices[i - 1])
                diff += prices[i] - prices[i - 1];
        }
        return diff;
    }

    //LOOKUP_TABLE
    // recursion O3^n time O3^n space
    // class Solution
    // {
    //     int find_maxProfit(bool buy, int pos, vector<int> prices, int n, vector<int> &dp_buy, vector<int> &dp_sell)
    //     {
    //         if (pos >= n || (buy == true && pos == n - 1))
    //             return 0;
    //         else if (buy && dp_buy[pos] > 0)
    //             return dp_buy[pos];
    //         else if (!buy && dp_sell[pos] > 0)
    //             return dp_sell[pos];

    //         int profit = 0;
    //         //We have 3 options: Buy,Sell,Skip (current share)
    //         int skip = find_maxProfit(buy, pos + 1, prices, n, dp_buy, dp_sell); //Skip case
    //         if (buy)
    //         {
    //             profit = -prices[pos] + find_maxProfit(false, pos + 1, prices, n, dp_buy, dp_sell);
    //             dp_buy[pos] = max(skip, profit);
    //             return dp_buy[pos];
    //         }
    //         else
    //         {
    //             profit = prices[pos] + find_maxProfit(true, pos + 1, prices, n, dp_buy, dp_sell);
    //             dp_sell[pos] = max(skip, profit);
    //             return dp_sell[pos];
    //         }

    //         //Return by taking max of all 3 cases
    //         return max(profit, skip);
    //     }

    // public:
    //     int maxProfit(vector<int> &prices)
    //     {

    //         ios_base::sync_with_stdio(false);
    //         cin.tie(NULL);

    //         int n = prices.size();
    //         if (n == 0 || n == 1)
    //             return 0;
    //         else if (n == 2)
    //             return max(0, prices[1] - prices[0]);

    //         vector<int> dp_buy(n, 0);
    //         vector<int> dp_sell(n, 0);
    //         //vector<int> dp(n,0);

    //         return find_maxProfit(true, 0, prices, n, dp_buy, dp_sell);
    //     }
    // };

    // leetcode solution

    // recursion On^n time On space
    // class Solution
    // {
    // public
    //     int maxProfit(int[] prices)
    //     {
    //         return calculate(prices, 0);
    //     }

    // public
    //     int calculate(int prices[], int s)
    //     {
    //         if (s >= prices.length)
    //             return 0;
    //         int max = 0;
    //         for (int start = s; start < prices.length; start++)
    //         {
    //             int maxprofit = 0;
    //             for (int i = start + 1; i < prices.length; i++)
    //             {
    //                 if (prices[start] < prices[i])
    //                 {
    //                     int profit = calculate(prices, i + 1) + prices[i] - prices[start];
    //                     if (profit > maxprofit)
    //                         maxprofit = profit;
    //                 }
    //             }
    //             if (maxprofit > max)
    //                 max = maxprofit;
    //         }
    //         return max;
    //     }
    // }

    // finding peaks and valleys
    // class Solution
    // {
    // public
    //     int maxProfit(int[] prices)
    //     {
    //         int i = 0;
    //         int valley = prices[0];
    //         int peak = prices[0];
    //         int maxprofit = 0;
    //         while (i < prices.length - 1)
    //         {
    //             while (i < prices.length - 1 && prices[i] >= prices[i + 1])
    //                 i++;
    //             valley = prices[i];
    //             while (i < prices.length - 1 && prices[i] <= prices[i + 1])
    //                 i++;
    //             peak = prices[i];
    //             maxprofit += peak - valley;
    //         }
    //         return maxprofit;
    //     }
    // }

    // keep adding profit method like techdose On time O1 space

    // did not get TLE On^2 time
    // int maxProfit(vector<int> &prices)
    // {
    //             int ans=0;

    //             for (int i=0; i<prices.size(); i++) {
    //                 int start = prices[i];
    //                 int local = 0;
    //                 int end = prices[i];
    //                 int j;
    //                 for (j=i+1; j<prices.size(); j++) {
    //                     if (prices[j]>end) {
    //                         end = prices[j];
    //                     }
    //                     else {
    //                         local += end - start;

    //                         start = prices[j];
    //                         end = prices[j];

    //                     }
    //                 }

    //                 if (j==prices.size())
    //                     local+=end - start;

    //                 // cout<<local<<endl;

    //                 ans = max(ans, local);
    //             }

    //             return ans;
    //         }
};
// @lc code=end
