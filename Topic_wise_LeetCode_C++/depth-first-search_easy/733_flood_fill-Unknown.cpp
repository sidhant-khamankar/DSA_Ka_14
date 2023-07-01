/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution
{
public:
    //gfg like my solution bsf
    // leetcode Code library solution like my solution but recursive dsf On time On space
    class Solution
    {
    public
        int[][] floodFill(int[][] image, int sr, int sc, int newColor)
        {
            int color = image[sr][sc];
            if (color != newColor)
                dfs(image, sr, sc, color, newColor);
            return image;
        }
    public
        void dfs(int[][] image, int r, int c, int color, int newColor)
        {
            if (image[r][c] == color)
            {
                image[r][c] = newColor;
                if (r >= 1)
                    dfs(image, r - 1, c, color, newColor);
                if (c >= 1)
                    dfs(image, r, c - 1, color, newColor);
                if (r + 1 < image.length)
                    dfs(image, r + 1, c, color, newColor);
                if (c + 1 < image[0].length)
                    dfs(image, r, c + 1, color, newColor);
            }
        }
    }
    // My solution On*m time On*m space
    // vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    // {

    //     int R = image.size();
    //     int C = image[0].size();
    //     queue<pair<int, int>> q;
    //     q.push({sr, sc});

    //     while (q.empty() == false)
    //     {
    //         int r = q.front().first;
    //         int c = q.front().second;
    //         q.pop();

    //         if (image[r][c] != newColor)
    //         {
    //             if (r - 1 >= 0 && image[r - 1][c] == image[r][c])
    //                 q.push({r - 1, c});
    //             if (c + 1 < C && image[r][c + 1] == image[r][c])
    //                 q.push({r, c + 1});
    //             if (r + 1 < R && image[r + 1][c] == image[r][c])
    //                 q.push({r + 1, c});
    //             if (c - 1 >= 0 && image[r][c - 1] == image[r][c])
    //                 q.push({r, c - 1});

    //             image[r][c] = newColor;
    //         }
    //     }

    //     return image;
    // }
};
// @lc code=end
