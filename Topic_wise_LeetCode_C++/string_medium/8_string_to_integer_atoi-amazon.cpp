/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start

// My solution On time On space
class Solution
{
public:
    int myAtoi(string s)
    {
        if (s == "")
            return 0;
        int i = 0;
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        int sign = 1;
        if (i < s.size() && s[i] == '+')
        {
            sign = 1;
            i++;
        }
        else if (i < s.size() && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        string num;
        if (s[i] < 48 || s[i] > 57)
            return 0;
        while (i < s.size() && 48 <= s[i] && s[i] <= 57)
        {
            // cout << s[i] << endl;
            num.push_back(s[i]);
            i++;
        }
        long long n = 0;
        int j = 0;
        for (int k = num.size() - 1; k >= 0; k--)
        {
            if (sign * ((num[k] - 48) * pow(10, j)) < (-1 * pow(2, 31)))
                return -1 * pow(2, 31);
            else if (((num[k] - 48) * pow(10, j)) > (pow(2, 31) - 1))
                return pow(2, 31) - 1;

            n += (num[k] - 48) * pow(10, j);
            // cout << num[k] << endl;
            // cout << n << endl;
            j++;
        }
        n *= sign;
        if (n < (-1 * pow(2, 31)))
            return -1 * pow(2, 31);
        else if (n > (pow(2, 31) - 1))
            return pow(2, 31) - 1;

        return n;
    }
};
// @lc code=end
