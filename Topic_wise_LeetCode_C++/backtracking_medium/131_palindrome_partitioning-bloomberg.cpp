/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
public:
    // Striver solution On*2^n time On space like my solution
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }

    void func(int index, string s, vector<string> &path,
              vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i)
        {
            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
// class Solution
// {
// public:
//     // My solution On*2^n time On space
//     bool isPalindrome(string sub)
//     {
//         if (sub == string(sub.rbegin(), sub.rend()))
//             return true;
//         else
//             return false;
//     }
//     void recur(int ind, vector<vector<string>> &ans, vector<string> &ds, int n, string s)
//     {
//         if (ind == n)
//         {
//             ans.push_back(ds);
//             return;
//         }
//         int len = 1;
//         for (int i = ind; i < n; i++)
//         {
//             string sub = s.substr(ind, len++);
//             if (isPalindrome(sub))
//             {
//                 ds.push_back(sub);
//                 recur(i + 1, ans, ds, n, s);
//                 ds.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s)
//     {
//         vector<vector<string>> ans;
//         vector<string> ds;
//         int n = s.size();
//         recur(0, ans, ds, n, s);
//         return ans;
//     }
// };
// @lc code=end
