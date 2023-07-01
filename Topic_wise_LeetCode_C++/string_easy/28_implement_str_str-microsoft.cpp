/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start

// My solution On*m time O1 space
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                int j = i;
                int k = 0;
                while (j < haystack.size() && k < needle.size() && haystack[j] == needle[k])
                {
                    j++;
                    k++;
                }
                if (k == needle.size())
                    return i;
            }
        }

        return -1;
    }
};
// @lc code=end
