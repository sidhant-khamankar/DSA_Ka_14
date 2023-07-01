/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
class Solution
{
public:
    // Naresh gupta 1st approach like my solution
    // Solution 2: TC - O(m*n) & SC - O(1)

    //     class Solution2
    //     {
    //     public
    //         void gameOfLife2(int[][] board)
    //         {
    //             int R = board.length;
    //             int C = board[0].length;

    //             int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
    //             int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};

    //             for (int i = 0; i < R; i++)
    //             {
    //                 for (int j = 0; j < C; j++)
    //                 {
    //                     int liveCounts = 0;
    //                     for (int k = 0; k < 8; k++)
    //                         if (isSafe(i + dx[k], j + dy[k], R, C) && Math.abs(board[i + dx[k]][j + dy[k]]) == 1)
    //                             liveCounts++;

    //                     if (board[i][j] == 0 && liveCounts == 3)
    //                         board[i][j] = 2;
    //                     if (board[i][j] == 1 && (liveCounts < 2 || liveCounts > 3))
    //                         board[i][j] = -1;
    //                 }
    //             }

    //             for (int i = 0; i < R; i++)
    //                 for (int j = 0; j < C; j++)
    //                     board[i][j] = board[i][j] > 0 ? 1 : 0;
    //         }

    //     private
    //         boolean isSafe(int x, int y, int R, int C)
    //         {
    //             return (x >= 0 && x < R && y >= 0 && y < C);
    //         }
    //     }
    // }
    // My solution like naresh gupta 1st approach On*m time On*m space
    void
    update(int r, int c, vector<vector<int>> &board, vector<vector<int>> &updates)
    {
        vector<int> rows = {0, -1, 0, 1, -1, 1, -1, 1};
        vector<int> cols = {1, 0, -1, 0, -1, 1, 1, -1};

        int live = 0;
        for (int i = 0; i < 8; i++)
        {
            if (r + rows[i] >= 0 && r + rows[i] < board.size() && c + cols[i] >= 0 && c + cols[i] < board[0].size())
            {
                if (board[r + rows[i]][c + cols[i]] == 1)
                    live++;
            }
        }

        if (board[r][c] == 0 && live == 3)
        {
            updates.push_back({r, c, 1});
        }
        else
        {
            if (live < 2)
                updates.push_back({r, c, 0});
            else if (live > 3)
                updates.push_back({r, c, 0});
        }
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> updates;

        for (int r = 0; r < board.size(); ++r)
        {
            for (int c = 0; c < board[0].size(); ++c)
            {
                update(r, c, board, updates);
            }
        }

        for (vector<int> v : updates)
        {
            board[v[0]][v[1]] = v[2];
        }
    }
};
// @lc code=end
