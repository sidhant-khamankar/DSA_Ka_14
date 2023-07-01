/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution
{
public:
    //did not get
    // Leetcode discuss dfs On*m time On*m recursion space
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    islands++;
                    eraseIslands(grid, i, j);
                }
            }
        }
        return islands;
    }

private:
    void eraseIslands(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0')
        {
            return;
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);
        eraseIslands(grid, i + 1, j);
        eraseIslands(grid, i, j - 1);
        eraseIslands(grid, i, j + 1);
    }

    //  // Leetcode discuss bfs On*m time On*m queue space
    // public:
    //     int numIslands(vector<vector<char>> &grid)
    //     {
    //         int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
    //         for (int i = 0; i < m; i++)
    //         {
    //             for (int j = 0; j < n; j++)
    //             {
    //                 if (grid[i][j] == '1')
    //                 {
    //                     islands++;
    //                     grid[i][j] = '0';
    //                     queue<pair<int, int>> todo;
    //                     todo.push({i, j});
    //                     while (!todo.empty())
    //                     {
    //                         pair<int, int> p = todo.front();
    //                         todo.pop();
    //                         for (int k = 0; k < 4; k++)
    //                         {
    //                             int r = p.first + offsets[k], c = p.second + offsets[k + 1];
    //                             if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1')
    //                             {
    //                                 grid[r][c] = '0';
    //                                 todo.push({r, c});
    //                             }
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //         return islands;
    //     }
};
// @lc code=end
