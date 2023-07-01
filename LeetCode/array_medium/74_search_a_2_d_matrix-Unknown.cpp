/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Striver Solution Olog(n*m) time O1 space
        if (!matrix.size())
            return false;
        int n = matrix.size();
        int m = matrix[0].size();

        int lo = 0;
        int hi = (n * m) - 1;

        while (lo <= hi)
        {
            int mid = (lo + (hi - lo)) / 2;
            if (matrix[mid / m][mid % m] == target)
            {
                return true;
            }
            if (matrix[mid / m][mid % m] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
        // // My solution Orow*Logcolumn
        // if (matrix.size() == 1)
        //     return binary_search(matrix[0].begin(), matrix[0].end(), target);
        // for (int r = 0; r < matrix.size(); r++)
        // {
        //     if ((r == 0) && (target < matrix[r][0]))
        //     {
        //         return false;
        //     }
        //     if (target <= matrix[r][0])
        //     {
        //         int row = r - 1;
        //         if (target == matrix[r][0])
        //             row = r;
        //         return binary_search(matrix[row].begin(), matrix[row].end(), target);
        //     }
        //     if ((r == matrix.size() - 1) && (target <= matrix[r][matrix[0].size() - 1]))
        //     {
        //         return binary_search(matrix[r].begin(), matrix[r].end(), target);
        //     }
        // }
        // return false; //target larger than largest element in matrix
    }
};
// @lc code=end
