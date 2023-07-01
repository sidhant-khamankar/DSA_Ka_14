/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution
{
public:
    //did not get

    //Leetcode discuss solution
    // bfs time OV+E
    //On^2 time On^2 space
    // explanation https://leetcode.com/problems/snakes-and-ladders/discuss/794701/C++:-bfs-oror-detailed-explanation-oror-faster-than-99.31
    //trick
    void getCoordinate(int n, int s, int &row, int &col)
    {
        row = n - 1 - (s - 1) / n;
        col = (s - 1) % n;
        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0))
            col = n - 1 - col;
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<bool> seen(n * n + 1, false);
        seen[1] = true;
        queue<pair<int, int>> q;
        q.push({1, 0});
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int row, col, s = p.first, dist = p.second;
            if (s == n * n) //while searching in breadth, we encounter dest, queue may not be empty at this point
                return dist;
            for (int i = 1; s + i <= n * n && i <= 6; i++)
            {
                getCoordinate(n, s + i, row, col);
                int sfinal = board[row][col] == -1 ? s + i : board[row][col]; // check for snake or ladder
                if (seen[sfinal] == false)
                {
                    seen[sfinal] = true;
                    q.push({sfinal, dist + 1});
                }
            }
        }
        return -1;
    }

    // Codebix java solution
    //On^2 time On^2 space

    // public
    //     int snakesAndLadders(int[][] board)
    //     {
    //         int n = board.length;
    //         int steps = 0;
    //         Queue<Integer> q = new LinkedList<Integer>();
    //         boolean visited[][] = new boolean[n][n];
    //         q.add(1);
    //         visited[n - 1][0] = true;
    //         while (!q.isEmpty())
    //         {
    //             int size = q.size();

    //             for (int i = 0; i < size; i++)
    //             {
    //                 int x = q.poll();
    //                 if (x == n * n)
    //                     return steps;
    //                 for (int k = 1; k <= 6; k++)
    //                 {
    //                     if (k + x > n * n)
    //                         break;
    //                     int pos[] = findCoordinates(k + x, n);
    //                     int r = pos[0];
    //                     int c = pos[1];
    //                     if (visited[r][c] == true)
    //                         continue;
    //                     visited[r][c] = true;
    //                     if (board[r][c] == -1)
    //                     {
    //                         q.add(k + x);
    //                     }
    //                     else
    //                     {
    //                         q.add(board[r][c]);
    //                     }
    //                 }
    //             }

    //             steps++;
    //         }
    //         return -1;
    //     }

    // public
    //     int[] findCoordinates(int curr, int n)
    //     {
    //         int r = n - (curr - 1) / n - 1;
    //         int c = (curr - 1) % n;
    //         if (r % 2 == n % 2)
    //         {
    //             return new int[]{r, n - 1 - c};
    //         }
    //         else
    //         {
    //             return new int[]{r, c};
    //         }
    //     }
};
// @lc code=end
