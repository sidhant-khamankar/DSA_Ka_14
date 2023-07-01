/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start

class Solution
{
public:
    // On^2 time On space
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1;
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
            {
                break;
            }

            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};
// My solution TLE for cases
// class Solution
// {
// public:
//     void recur(vector<int> seq, vector<int> &ds, vector<vector<int>> &ans, int n, int &count, int k)
//     {
//         if (ds.size() == n)
//         {
//             ans.push_back(ds);
//             count++;
//             return;
//         }
//         for (int i = 0; i < n; i++)
//         {
//             if (count == k)
//                 break;
//             if (find(ds.begin(), ds.end(), seq[i]) == ds.end())
//             {
//                 ds.push_back(seq[i]);
//                 recur(seq, ds, ans, n, count, k);
//                 ds.pop_back();
//             }
//         }
//     }
//     string getPermutation(int n, int k)
//     {
//         vector<int> seq;

//         for (int i = 0; i < n; i++)
//         {
//             seq.push_back(i + 1);
//         }
//         vector<int> ds;
//         vector<vector<int>> ans;
//         int count = 0;
//         recur(seq, ds, ans, n, count, k);
//         string str;
//         for (int i = 0; i < n; i++)
//         {
//             str += to_string(ans[k - 1][i]);
//         }
//         return str;
//     }
// };
// @lc code=end
