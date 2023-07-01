/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
public:
    // Neetcode solution Approach 2
    // On time O1 space no builtin function isalnum
    bool CheckAlphaNum(char c)
    {
        // cout << (int)c << " " << (int)'A' << " " << (int)'a' << " " << (int)'0' << endl;
        return ((('A' <= c) && (c <= 'Z')) ||
                (('a' <= c) && (c <= 'z')) ||
                (('0' <= c) && (c <= '9')));
    }
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;

        while (l < r)
        {
            while ((l < r) && !CheckAlphaNum(s[l]))
                l += 1;
            while (r > l && !CheckAlphaNum(s[r]))
                r -= 1;

            if (tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }

            l = l + 1;
            r = r - 1;
        }
        return true;
    }

    // My solution On time On space like neetcode approach 1
    // bool isPalindrome(string s)
    // {
    //     string pString;

    //     for (char c : s)
    //     {
    //         if (isalnum(c))
    //         {
    //             pString.push_back(tolower(c));
    //         }
    //     }

    //     int start = 0, end = pString.size() - 1;
    //     while (start < end)
    //     {
    //         if (pString[start] != pString[end])
    //             return false;

    //         start++;
    //         end--;
    //     }

    //     return true;
    // }
};
// @lc code=end
