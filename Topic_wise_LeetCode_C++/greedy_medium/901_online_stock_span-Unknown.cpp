/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start

// TechDose solution On time On space
//same complexity as my solution
// class StockSpanner
// {
//     stack<pair<int, int>> s; //1st is index and 2nd is value
//     int index;

// public:
//     StockSpanner()
//     {
//         ios::sync_with_stdio(false);
//         cin.tie(0);
//         index = -1;
//     }

//     int next(int price)
//     {
//         index += 1;
//         while (!s.empty() && s.top().second <= price) //Find the previous greater element
//             s.pop();
//         //If there is no previous greater element
//         if (s.empty())
//         {
//             s.push({index, price});
//             return index + 1;
//         }

//         int result = s.top().first;
//         s.push({index, price});
//         return index - result;
//     }
// };

// My solution On time On space

class StockSpanner
{
public:
    vector<int> prices;
    StockSpanner()
    {
    }

    int next(int price)
    {
        prices.push_back(price);
        int span = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (prices[i] <= price)
                span++;
            else
            {
                break;
            }
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
