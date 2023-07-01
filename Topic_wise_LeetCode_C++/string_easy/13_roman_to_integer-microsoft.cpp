/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

// my solution On time O1 space
class Solution
{
public:
    int romanToInt(string s)
    {
        int num = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'I')
                num += 1;
            else if (s[i] == 'V')
            {
                if (i - 1 >= 0 && s[i - 1] == 'I')
                {
                    num -= 1;
                    num += 4;
                }
                else
                    num += 5;
            }
            else if (s[i] == 'X')
            {
                if (i - 1 >= 0 && s[i - 1] == 'I')
                {
                    num -= 1;
                    num += 9;
                }
                else
                    num += 10;
            }
            else if (s[i] == 'L')
            {
                if (i - 1 >= 0 && s[i - 1] == 'X')
                {
                    num -= 10;
                    num += 40;
                }
                else
                    num += 50;
            }
            else if (s[i] == 'C')
            {
                if (i - 1 >= 0 && s[i - 1] == 'X')
                {
                    num -= 10;
                    num += 90;
                }
                else
                    num += 100;
            }
            else if (s[i] == 'D')
            {
                if (i - 1 >= 0 && s[i - 1] == 'C')
                {
                    num -= 100;
                    num += 400;
                }
                else
                    num += 500;
            }
            else if (s[i] == 'M')
            {
                if (i - 1 >= 0 && s[i - 1] == 'C')
                {
                    num -= 100;
                    num += 900;
                }
                else
                    num += 1000;
            }
        }

        return num;
    }
};
// @lc code=end
