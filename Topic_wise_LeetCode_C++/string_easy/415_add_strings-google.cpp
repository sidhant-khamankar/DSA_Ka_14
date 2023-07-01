/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
// Coding decoded solution better formulas
// class Solution
// {

//     // TC : O(len1+ len2)
// public
//     String addStrings(String num1, String num2)
//     {
//         String ans = "";

//         int it1 = num1.length() - 1;
//         int it2 = num2.length() - 1;
//         int carry = 0;
//         int sum = 0;
//         while (it1 >= 0 && it2 >= 0)
//         {
//             int digit1 = num1.charAt(it1) - '0';
//             int digit2 = num2.charAt(it2) - '0';
//             sum = digit1 + digit2 + carry;
//             carry = sum / 10;
//             sum = sum % 10;
//             ans = sum + ans;
//             it1--;
//             it2--;
//         }

//         while (it1 >= 0)
//         {
//             int digit1 = num1.charAt(it1) - '0';
//             sum = digit1 + carry;
//             carry = sum / 10;
//             sum = sum % 10;

//             ans = sum + ans;

//             it1--;
//         }

//         while (it2 >= 0)
//         {
//             int digit2 = num2.charAt(it2) - '0';
//             sum = digit2 + carry;
//             carry = sum / 10;
//             sum = sum % 10;
//             ans = sum + ans;

//             it2--;
//         }

//         if (carry == 1)
//         {
//             ans = "1" + ans;
//         }

//         return ans;
//     }
// }
class Solution
{
public:
    // My solution On+m time On space
    string helper(string &num1, string num2)
    {
        int carry = 0;
        string ans;

        if (num1.size() <= num2.size())
        {
            for (int i = 0; i < num1.size(); i++)
            {
                int curr = num1[num1.size() - 1 - i] - '0' + num2[num2.size() - 1 - i] - '0' + carry;
                if (curr >= 10)
                {
                    carry = curr == 20 ? 2 : 1;
                    curr = curr == 20 || curr == 10 ? 0 : curr - 10;
                }
                else
                {
                    carry = 0;
                }

                ans.push_back(curr + '0');
            }

            for (int j = num2.size() - num1.size() - 1; j >= 0; j--)
            {
                int curr = num2[j] - '0' + carry;
                if (curr >= 10)
                {
                    carry = curr == 20 ? 2 : 1;
                    curr = curr == 20 || curr == 10 ? 0 : curr - 10;
                }
                else
                {
                    carry = 0;
                }

                ans.push_back(curr + '0');
            }

            if (carry > 0)
            {
                ans.push_back(carry + '0');
                carry = 0;
            }
            return ans;
        }
        else
        {
            return "";
        }
    }
    string addStrings(string num1, string num2)
    {
        string ans = helper(num1, num2);
        if (ans.size() == 0)
        {
            ans = helper(num2, num1);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end
