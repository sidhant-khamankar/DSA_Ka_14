/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution
{
public:
    // Binary search didn't click, halfway
    // Neetcode solution O(logmax(p)*p) time O1 space
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();

        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++)
        {
            high = max(high, piles[i]);
        }

        int result = high;

        while (low <= high)
        {
            int k = low + (high - low) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++)
            {
                hours += ceil((double)piles[i] / k);
            }
            if (hours <= h)
            {
                result = min(result, k);
                high = k - 1;
            }
            else
            {
                low = k + 1;
            }
        }

        return result;
    }
};
// @lc code=end
