/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
//Michael Muinos gfg solution On time O1 space
// Function to convert decimal to Roman Numerals
int printRoman(int number)
{
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (number > 0)
    {
        int div = number / num[i];
        number = number % num[i];
        while (div--)
        {
            cout << sym[i];
        }
        i--;
    }
}
//My solution On+n time On space
// class Solution
// {
// public:
//     string intToRoman(int num)
//     {
//         int temp = num;
//         vector<int> dig;

//         while (temp > 0)
//         {
//             dig.push_back(temp % 10);
//             temp = temp / 10;
//         }

//         string ans;
//         for (int i = dig.size() - 1; i >= 0; i--)
//         {
//             if (i == 0)
//             {
//                 if (dig[i] < 4)
//                 {
//                     for (int j = 0; j < dig[i]; j++)
//                         ans += 'I';
//                 }
//                 else if (dig[i] == 4)
//                 {
//                     ans += "IV";
//                 }
//                 else if (dig[i] == 9)
//                     ans += "IX";
//                 else
//                 {
//                     ans += 'V';
//                     for (int j = 6; j <= dig[i]; j++)
//                         ans += 'I';
//                 }
//             }
//             else if (i == 1)
//             {
//                 if (dig[i] < 4)
//                 {
//                     for (int j = 0; j < dig[i]; j++)
//                         ans += 'X';
//                 }
//                 else if (dig[i] == 4)
//                     ans += "XL";
//                 else if (dig[i] == 9)
//                     ans += "XC";
//                 else
//                 {
//                     ans += 'L';
//                     for (int j = 6; j <= dig[i]; j++)
//                         ans += 'X';
//                 }
//             }
//             else if (i == 2)
//             {
//                 if (dig[i] < 4)
//                 {
//                     for (int j = 0; j < dig[i]; j++)
//                         ans += 'C';
//                 }
//                 else if (dig[i] == 4)
//                     ans += "CD";
//                 else if (dig[i] == 9)
//                     ans += "CM";
//                 else
//                 {
//                     ans += 'D';
//                     for (int j = 6; j <= dig[i]; j++)
//                         ans += 'C';
//                 }
//             }
//             else if (i == 3)
//             {
//                 if (dig[i] < 4)
//                 {
//                     for (int j = 0; j < dig[i]; j++)
//                         ans += 'M';
//                 }
//             }
//         }

//         return ans;
//     }
// };
// @lc code=end
