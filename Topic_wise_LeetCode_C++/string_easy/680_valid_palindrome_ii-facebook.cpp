/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution
{
public:
    // did not get
    // Leetcode solution On time O1 space
    // class Solution
    // {
    // private
    //     boolean checkPalindrome(String s, int i, int j)
    //     {
    //         while (i < j)
    //         {
    //             if (s.charAt(i) != s.charAt(j))
    //             {
    //                 return false;
    //             }

    //             i++;
    //             j--;
    //         }

    //         return true;
    //     }

    // public
    //     boolean validPalindrome(String s)
    //     {
    //         int i = 0;
    //         int j = s.length() - 1;

    //         while (i < j)
    //         {
    //             // Found a mismatched pair - try both deletions
    //             if (s.charAt(i) != s.charAt(j))
    //             {
    //                 return (checkPalindrome(s, i, j - 1) || checkPalindrome(s, i + 1, j));
    //             }

    //             i++;
    //             j--;
    //         }

    //         return true;
    //     }
    // }

    // Neetcode solution On time On space

    bool
    validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
            {
                string skipL = s.substr(l + 1, r - l);
                string skipR = s.substr(l, r - l);

                string skipLrev = string(skipL.rbegin(), skipL.rend());
                string skipRrev = string(skipR.rbegin(), skipR.rend());

                // cout << skipL << "\nRevL: " << skipLrev << endl;
                // cout << skipR << "\nRevR: " << skipRrev << endl;

                return (skipL == skipLrev or skipR == skipRrev);
            }
            l = l + 1;
            r = r - 1;
        }

        return true;
    }
};
// @lc code=end
