/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    // My solution O(n^2)*(v+E) time OV space,
    // leetcode solution same as mine Orc time Orc space
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == 0)
                {
                    int area = dfs(grid, visited, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    //depth first search function
    int dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j)
    {
        //if the current node is out of grid or it is not a land or it has been visited
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;    //mark zero for subsequent searches
        visited[i][j] = 1; //mark as visited
        return 1 + dfs(grid, visited, i - 1, j) + dfs(grid, visited, i + 1, j) + dfs(grid, visited, i, j - 1) + dfs(grid, visited, i, j + 1);
        // left, right, up, down
    }

    // Leetcode solution Orc time Orc space
    // Iterative using stack
    // class Solution
    // {
    // public
    //     int maxAreaOfIsland(int[][] grid)
    //     {
    //         boolean[][] seen = new boolean[grid.length][grid[0].length];
    //         int[] dr = new int[]{1, -1, 0, 0};
    //         int[] dc = new int[]{0, 0, 1, -1};

    //         int ans = 0;
    //         for (int r0 = 0; r0 < grid.length; r0++)
    //         {
    //             for (int c0 = 0; c0 < grid[0].length; c0++)
    //             {
    //                 if (grid[r0][c0] == 1 && !seen[r0][c0])
    //                 {
    //                     int shape = 0;
    //                     Stack<int[]> stack = new Stack();
    //                     stack.push(new int[]{r0, c0});
    //                     seen[r0][c0] = true;
    //                     while (!stack.empty())
    //                     {
    //                         int[] node = stack.pop();
    //                         int r = node[0], c = node[1];
    //                         shape++;
    //                         for (int k = 0; k < 4; k++)
    //                         {
    //                             int nr = r + dr[k];
    //                             int nc = c + dc[k];
    //                             if (0 <= nr && nr < grid.length &&
    //                                 0 <= nc && nc < grid[0].length &&
    //                                 grid[nr][nc] == 1 && !seen[nr][nc])
    //                             {
    //                                 stack.push(new int[]{nr, nc});
    //                                 seen[nr][nc] = true;
    //                             }
    //                         }
    //                     }
    //                     ans = Math.max(ans, shape);
    //                 }
    //             }
    //         }
    //         return ans;
    //     }
    // }
};
// @lc code=end
