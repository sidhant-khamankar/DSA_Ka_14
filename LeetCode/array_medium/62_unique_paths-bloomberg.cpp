/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int recur(int rows, int columns, int m, int n, vector<vector<int>> &matrix)
    {
        // Omn time Omn space
        int sub_ans = 0;
        if ((rows == m - 1) && (columns == n - 1))
            return 1;
        if ((rows >= m) || (columns >= n))
            return 0;
        int ans1, ans2;
        if (matrix[rows + 1][columns] != -1)
            ans1 = matrix[rows + 1][columns];
        else
        {
            ans1 = recur(rows + 1, columns, m, n, matrix);
            matrix[rows + 1][columns] = ans1;
        }
        if (matrix[rows][columns + 1] != -1)
            ans2 = matrix[rows][columns + 1];
        else
        {
            ans2 = recur(rows, columns + 1, m, n, matrix);
            matrix[rows][columns + 1] = ans2;
        }
        sub_ans = ans1 + ans2;
        return sub_ans;
    }
    int uniquePaths(int m, int n)
    {
        // int rows = m - 1;
        // int columns = n - 1;
        // vector<vector<int>> matrix(m + 1, vector<int>(n + 1, -1));
        // return recur(0, 0, m, n, matrix);

        //Striver Solution Combinations Om-1 or On-1 time O1 space
        int N = n + m - 2;
        int r = n - 1;
        double res = 1;
        for (int i = 1; i <= r; i++)
            res = res * (N - r + 1) / i;
        return (int)res;
    }
};
// @lc code=end
