/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution
{
    // Techdose solution On*m time O1 space
    vector<int> Solution::spiralOrder(const vector<vector<int>> &A)
    {

        int T, B, L, R, dir;
        T = 0;
        B = A.size() - 1;
        L = 0;
        R = A[0].size() - 1;
        dir = 0;
        int i;
        vector<int> ans;

        while (T <= B && L <= R)
        {
            if (dir == 0)
            {
                for (i = L; i <= R; i++)
                    ans.push_back(A[T][i]);
                T++;
            }
            else if (dir == 1)
            {
                for (i = T; i <= B; i++)
                    ans.push_back(A[i][R]);
                R--;
            }
            else if (dir == 2)
            {
                for (i = R; i >= L; i--)
                    ans.push_back(A[B][i]);
                B--;
            }
            else if (dir == 3)
            {
                for (i = B; i >= T; i--)
                    ans.push_back(A[i][L]);
                L++;
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }

    // ###################################################
    // ###################################################

    // My solution On*m time On*m space
private:
    void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<int>> &matrix, vector<int> &ans)
    {
        cout << matrix[i][j] << endl;
        if (j + 1 < matrix[0].size() && visited[i][j + 1] == -1)
        {
            while (j + 1 < matrix[0].size() && visited[i][j + 1] == -1)
            {
                j++;
                ans.push_back(matrix[i][j]);
                visited[i][j] = 1;
            }
            dfs(i, j, visited, matrix, ans);
        }
        else if (i + 1 < matrix.size() && visited[i + 1][j] == -1)
        {
            while (i + 1 < matrix.size() && visited[i + 1][j] == -1)
            {
                i++;
                ans.push_back(matrix[i][j]);
                visited[i][j] = 1;
            }
            dfs(i, j, visited, matrix, ans);
        }
        else if (j - 1 >= 0 && visited[i][j - 1] == -1)
        {
            while (j - 1 >= 0 && visited[i][j - 1] == -1)
            {
                j--;
                ans.push_back(matrix[i][j]);
                visited[i][j] = 1;
            }
            dfs(i, j, visited, matrix, ans);
        }
        else if (i - 1 >= 0 && visited[i - 1][j] == -1)
        {
            while (i - 1 >= 0 && visited[i - 1][j] == -1)
            {
                i--;
                ans.push_back(matrix[i][j]);
                visited[i][j] = 1;
            }
            dfs(i, j, visited, matrix, ans);
        }
    }

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), -1));
        ans.push_back(matrix[0][0]);
        visited[0][0] = 1;
        dfs(0, 0, visited, matrix, ans);

        return ans;
    }
};
// @lc code=end
