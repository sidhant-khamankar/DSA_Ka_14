/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // did not get
    // Neetcode solution On time O1 space
    int characterReplacement(string s, int k)
    {
        vector<int> count(26);
        int maxCount = 0;

        int i = 0;
        int j = 0;

        int result = 0;

        while (j < s.size())
        {
            count[s[j] - 'A']++;
            maxCount = max(maxCount, count[s[j] - 'A']);
            if (j - i + 1 - maxCount > k)
            {
                count[s[i] - 'A']--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};
// @lc code=end
