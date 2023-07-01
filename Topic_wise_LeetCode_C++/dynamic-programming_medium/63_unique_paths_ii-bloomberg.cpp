/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
public:
    // My solution Onm time Onm space
    int recur(int r, int c, vector<vector<int>> &obstacleGrid, vector<vector<int>> &visited, int rows, int cols, vector<vector<int>> &dp)
    {

        if (r >= rows || c >= cols || r < 0 || c < 0 || obstacleGrid[r][c] == 1)
        {
            return 0;
        }

        if (r == rows - 1 && c == cols - 1)
        {
            return dp[r][c] = 1;
        }

        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }
        if (visited[r][c] == -1 && obstacleGrid[r][c] == 0)
        {
            visited[r][c] = 1;
            return dp[r][c] = recur(r + 1, c, obstacleGrid, visited, rows, cols, dp) + recur(r, c + 1, obstacleGrid, visited, rows, cols, dp);
        }
        return 0;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        // make visited grid
        // recur
        // return if out of bounds
        // return 1 if reached finish

        int cols = obstacleGrid[0].size();
        int rows = obstacleGrid.size();

        if (obstacleGrid[rows - 1][cols - 1] == 1)
        {
            return 0;
        }
        vector<vector<int>> visited(rows + 1, vector<int>(cols + 1, -1));
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, -1));

        return recur(0, 0, obstacleGrid, visited, rows, cols, dp);
    }

    // Techdose solution like Leetcode solution Onm time O1 space top down approach
    // java
    // class Solution
    // {
    // public
    //     int uniquePathsWithObstacles(int[][] obstacleGrid)
    //     {

    //         int R = obstacleGrid.length;
    //         int C = obstacleGrid[0].length;

    //         // If the starting cell has an obstacle, then simply return as there would be
    //         // no paths to the destination.
    //         if (obstacleGrid[0][0] == 1)
    //         {
    //             return 0;
    //         }

    //         // Number of ways of reaching the starting cell = 1.
    //         obstacleGrid[0][0] = 1;

    //         // Filling the values for the first column
    //         for (int i = 1; i < R; i++)
    //         {
    //             obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
    //         }

    //         // Filling the values for the first row
    //         for (int i = 1; i < C; i++)
    //         {
    //             obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
    //         }

    //         // Starting from cell(1,1) fill up the values
    //         // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
    //         // i.e. From above and left.
    //         for (int i = 1; i < R; i++)
    //         {
    //             for (int j = 1; j < C; j++)
    //             {
    //                 if (obstacleGrid[i][j] == 0)
    //                 {
    //                     obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
    //                 }
    //                 else
    //                 {
    //                     obstacleGrid[i][j] = 0;
    //                 }
    //             }
    //         }

    //         // Return value stored in rightmost bottommost cell. That is the destination.
    //         return obstacleGrid[R - 1][C - 1];
    //     }
    // }
};
// @lc code=end
