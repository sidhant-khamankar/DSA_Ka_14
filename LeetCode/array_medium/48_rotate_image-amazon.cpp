/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution
{
public:
    //Striver solution On^2 time O1 space
    // * Brute Use one more matrix On^2 time On^2 space
    // put first row in last column, 2nd row in second last column and so on
    // * same as 2nd solution of leetcode solution On^2 time for both transpose and reverse O1 space
    // Transpose = rows becomes columns i,j becomes j,i
    // Reverse - two pointers method
    void transpose(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
    }
    void reverse(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size() / 2; j++)
            {
                swap(matrix[i][j], matrix[i][matrix[0].size() - 1 - j]);
            }
    }
    void rotate(vector<vector<int>> &matrix)
    {

        transpose(matrix);
        reverse(matrix);

        // My solution passing example test cases, failing actual test cases
        // for (int itr = 0; itr < matrix.size() / 2; itr++)
        // {
        //     int row = itr;
        //     int column = itr;
        //     int s;
        //     if (itr == 0)
        //         s = matrix.size() - itr;
        //     else
        //         s = matrix.size() - itr - 1;

        //     int p = 1;
        //     int i, j, k, l, m, n, o;
        //     int r = row;
        //     int c = column;
        //     int si1 = s;
        //     int si2 = s;
        //     int ro2 = row;
        //     while (p < s)
        //     {
        //         i = matrix[r][column];
        //         k = matrix[row][c + s - 1];
        //         matrix[row][c + s - 1] = i;
        //         m = matrix[r + s - 1][c + si2 - 1];
        //         matrix[r + s - 1][c + si2 - 1] = k;
        //         o = matrix[ro2 + s - 1][c];
        //         matrix[ro2 + s - 1][c] = m;
        //         matrix[r][column] = o;
        //         p++;
        //         row++;
        //         column++;
        //         si2--;
        //         ro2--;
        //     }
        // }
    }

    // ########################################################
    // ########################################################

    //Leetcode solution

    // // *Rotate in group of 4 Om time O1 space

    // class Solution
    // {
    // public
    //     void rotate(int[][] matrix)
    //     {
    //         int n = matrix.length;
    //         for (int i = 0; i < (n + 1) / 2; i++)
    //         {
    //             for (int j = 0; j < n / 2; j++)
    //             {
    //                 int temp = matrix[n - 1 - j][i];
    //                 matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
    //                 matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
    //                 matrix[j][n - 1 - i] = matrix[i][j];
    //                 matrix[i][j] = temp;
    //             }
    //         }
    //     }
    // }

    // //* Easier Transpose and reflect Om time for both O1 space
    // class Solution
    // {
    // public
    //     void rotate(int[][] matrix)
    //     {
    //         transpose(matrix);
    //         reflect(matrix);
    //     }

    // public
    //     void transpose(int[][] matrix)
    //     {
    //         int n = matrix.length;
    //         for (int i = 0; i < n; i++)
    //         {
    //             for (int j = i; j < n; j++)
    //             {
    //                 int tmp = matrix[j][i];
    //                 matrix[j][i] = matrix[i][j];
    //                 matrix[i][j] = tmp;
    //             }
    //         }
    //     }

    // public
    //     void reflect(int[][] matrix)
    //     {
    //         int n = matrix.length;
    //         for (int i = 0; i < n; i++)
    //         {
    //             for (int j = 0; j < n / 2; j++)
    //             {
    //                 int tmp = matrix[i][j];
    //                 matrix[i][j] = matrix[i][n - j - 1];
    //                 matrix[i][n - j - 1] = tmp;
    //             }
    //         }
    //     }
    // };
};
// @lc code=end
