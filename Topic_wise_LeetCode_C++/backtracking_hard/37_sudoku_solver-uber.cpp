/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
// Striver solution
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board) // start
    {
        solve(board); // fill the board
    }

    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++) // rows of board
        {
            for (int j = 0; j < board[0].size(); j++) // columns of board
            {
                if (board[i][j] == '.') //if empty cell
                {
                    for (char c = '1'; c <= '9'; c++) //try all numbers
                    {
                        if (isValid(board, i, j, c)) //check if number is valid
                        {
                            board[i][j] = c; // change the cell

                            if (solve(board)) // recursively call when current cell is changed
                                return true;
                            else
                                board[i][j] = '.'; // reset current cell
                        }
                    }

                    return false; //no number can be filled
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c) //check filled cell's column
                return false;

            if (board[row][i] == c) //check filled cell's row
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) //check the 3x3 grid
                return false;
        }
        // Check if we find the same num in
        // the particular 3*3 matrix,
        // we return false
        // int startRow = row - row % 3,
        //     startCol = col - col % 3;

        // for (int i = 0; i < 3; i++)
        //     for (int j = 0; j < 3; j++)
        //         if (grid[i + startRow][j +
        //                                startCol] == num)
        //             return false;
        return true;
    }
};
//My solution runtime error
// class Solution
// {
// public:
//     int checkGridMap(int row, int col, int no, vector<vector<int>> &gridmap)
//     {
//         int grid;
//         if (row >= 6)
//         {
//             if (col >= 6)
//                 grid = 8;
//             else if (col >= 3)
//                 grid = 7;
//             else
//                 grid = 6;
//         }
//         else if (row >= 3)
//         {
//             if (col >= 6)
//                 grid = 5;
//             else if (col >= 3)
//                 grid = 4;
//             else
//                 grid = 3;
//         }
//         else if (row >= 0)
//         {
//             if (col >= 6)
//                 grid = 2;
//             else if (col >= 3)
//                 grid = 1;
//             else
//                 grid = 0;
//         }
//         if (gridmap[grid][no] == 0)
//             return grid;
//         else
//             return -1;

//         return -1;
//     }
//     bool checkFill(vector<vector<int>> &sudoku)
//     {
//         for (int i = 0; i < sudoku.size(); i++)
//         {
//             for (int j = 0; j < sudoku.size(); j++)
//             {
//                 if (sudoku[i][j] == 0)
//                     return false;
//             }
//         }
//         return true;
//     }
//     void recur(vector<vector<int>> &sudoku, vector<vector<int>> &rowmap, vector<vector<int>> &colmap, vector<vector<int>> &gridmap, int n, vector<vector<int>> &ans)
//     {
//         if (checkFill(sudoku))
//         {
//             ans = sudoku;
//             return;
//         }
//         for (int col = 0; col < n; col++)
//         {
//             for (int row = 0; row < n; row++)
//             {
//                 if (sudoku[row][col] == 0)
//                 {
//                     for (int no = 1; no <= 9; no++)
//                     {
//                         int grid = checkGridMap(row, col, no, gridmap);
//                         if (rowmap[row][no] == 0 && colmap[col][no] == 0 && grid != -1)
//                         {
//                             rowmap[row][no] = 1;
//                             colmap[col][no] = 1;
//                             gridmap[grid][no] = 1;
//                             sudoku[row][col] = no;
//                             recur(sudoku, rowmap, colmap, gridmap, n, ans);
//                             rowmap[row][no] = 0;
//                             colmap[col][no] = 0;
//                             gridmap[grid][no] = 0;
//                             sudoku[row][col] = 0;
//                         }
//                         else
//                             return;
//                     }
//                 }
//             }
//         }
//     }
//     void solveSudoku(vector<vector<char>> &board)
//     {
//         vector<vector<int>> sudoku;
//         for (vector<char> ch : board)
//         {
//             vector<int> r;
//             for (char c : ch)
//             {
//                 if (c == '.')
//                 {
//                     r.push_back(0);
//                 }
//                 else
//                 {
//                     r.push_back(c - '0');
//                 }
//             }
//             sudoku.push_back(r);
//         }

//         int n = board.size();

//         vector<vector<int>> rowmap(n, vector<int>(n + 1, 0));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (sudoku[i][j] != 0)
//                     rowmap[i][sudoku[i][j]] = 1;
//             }
//         }

//         vector<vector<int>> colmap(n, vector<int>(n + 1, 0));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     colmap[i][sudoku[j][i]] = 1;
//             }
//         }
//         vector<vector<int>> gridmap(n, vector<int>(n + 1, 0));
//         for (int i = 0; i <= 2; i++)
//         {
//             for (int j = 0; j <= 2; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[0][sudoku[j][i]] = 1;
//             }
//             for (int j = 3; j <= 5; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[3][sudoku[j][i]] = 1;
//             }
//             for (int j = 6; j <= 8; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[6][sudoku[j][i]] = 1;
//             }
//         }
//         for (int i = 3; i <= 5; i++)
//         {
//             for (int j = 0; j <= 2; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[1][sudoku[j][i]] = 1;
//             }
//             for (int j = 3; j <= 5; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[4][sudoku[j][i]] = 1;
//             }
//             for (int j = 6; j <= 8; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[7][sudoku[j][i]] = 1;
//             }
//         }

//         for (int i = 6; i <= 8; i++)
//         {
//             for (int j = 0; j <= 2; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[2][sudoku[j][i]] = 1;
//             }
//             for (int j = 3; j <= 5; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[5][sudoku[j][i]] = 1;
//             }
//             for (int j = 6; j <= 8; j++)
//             {
//                 if (sudoku[j][i] != 0)
//                     gridmap[8][sudoku[j][i]] = 1;
//             }
//         }

//         vector<vector<int>> ans;
//         recur(sudoku, rowmap, colmap, gridmap, n, ans);
//         vector<vector<char>> str(n, vector<char>(n, '0'));
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 str[i][j] += ans[i][j];
//             }
//         }
//         board = str;
//     }
// };
// @lc code=end