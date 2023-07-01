/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution
{
public:
    // My solution, Aditya verma exponential time o2n space
    void recur(int n, string temp, vector<string> &ans, int open, int close, int curropen)
    {
        if (temp.size() == 2 * n)
        {
            ans.push_back(temp);
            return;
        }

        if (open > 0)
            recur(n, temp + '(', ans, open - 1, close, curropen + 1);
        if (close > 0 && curropen > 0)
            recur(n, temp + ')', ans, open, close - 1, curropen - 1);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp = "(";

        recur(n, temp, ans, n - 1, n, 1);

        return ans;
    }

    // Leetcode Solution
    // approach 2 Like my solution

    // class Solution
    // {
    // public
    //     List<String> generateParenthesis(int n)
    //     {
    //         List<String> ans = new ArrayList();
    //         backtrack(ans, new StringBuilder(), 0, 0, n);
    //         return ans;
    //     }

    // public
    //     void backtrack(List<String> ans, StringBuilder cur, int open, int close, int max)
    //     {
    //         if (cur.length() == max * 2)
    //         {
    //             ans.add(cur.toString());
    //             return;
    //         }

    //         if (open < max)
    //         {
    //             cur.append("(");
    //             backtrack(ans, cur, open + 1, close, max);
    //             cur.deleteCharAt(cur.length() - 1);
    //         }
    //         if (close < open)
    //         {
    //             cur.append(")");
    //             backtrack(ans, cur, open, close + 1, max);
    //             cur.deleteCharAt(cur.length() - 1);
    //         }
    //     }
    // }

    // did not understand approach 3

    // class Solution
    // {
    // public
    //     List<String> generateParenthesis(int n)
    //     {
    //         List<String> ans = new ArrayList();
    //         if (n == 0)
    //         {
    //             ans.add("");
    //         }
    //         else
    //         {
    //             for (int c = 0; c < n; ++c)
    //                 for (String left : generateParenthesis(c))
    //                     for (String right : generateParenthesis(n - 1 - c))
    //                         ans.add("(" + left + ")" + right);
    //         }
    //         return ans;
    //     }
    // }
};
// @lc code=end
