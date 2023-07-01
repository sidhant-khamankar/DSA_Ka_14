/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution
{
public:
    // gfg, algods solution binary search Olog ( abs(Mat[0][0] – Mat[n-1][n-1])  )*nlogn
    // This returns count of elements in matrix less than of equal to num
    int getElementsGreaterThanOrEqual(int num, int n, vector<vector<int>> &mat)
    {
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // if num is less than the first element then no more element in matrix
            // further are less than or equal to num
            if (mat[i][0] > num)
            {
                return ans;
            }
            // if num is greater than last element, it is greater than all elements
            // in that row
            if (mat[i][n - 1] <= num)
            {
                ans += n;
                continue;
            }
            // This contain the col index of last element in matrix less than of equal
            // to num
            int greaterThan = 0;
            for (int jump = n / 2; jump >= 1; jump /= 2)
            {
                while (greaterThan + jump < n &&
                       mat[i][greaterThan + jump] <= num)
                {
                    greaterThan += jump;
                }
            }

            ans += greaterThan + 1;
        }
        return ans;
    }

    // reuturs kth smallest index in the matrix
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        //  We know the answer lies between the first and the last element
        // So do a binary search on answer based on the number of elements
        // our current element is greater than the elements in the matrix
        int l = mat[0][0], r = mat[n - 1][n - 1];

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);

            if (greaterThanOrEqualMid >= k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    // gfg solution heap
    //Building a min - heap which takes O(n) time
    //Heapify k times which takes O(k Logn) time.
    // int kthSmallest(int mat[4][4], int n, int k)
    // {
    //     // USING LAMBDA FUNCTION
    //     // [=] IN LAMBDA FUNCTION IS FOR CAPTURING VARIABLES WHICH
    //     // ARE OUT OF SCOPE i.e. mat[r]
    //     // NOW, IT'LL COMPARE ELEMENTS OF HEAP BY ELEMENTS AT mat[first][second]
    //     // Capturing the value of mat by reference to prevent copying
    //     auto cmp = [&](pair<int, int> a, pair<int, int> b)
    //     {
    //         return mat[a.first][a.second] > mat[b.first][b.second];
    //     };

    //     //DECLARING priority_queue AND PUSHING FIRST ROW IN IT
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    //     for (int i = 0; i < n; i++)
    //     {
    //         pq.push({i, 0});
    //     }

    //     //RUNNING LOOP FOR (k-1) TIMES
    //     for (int i = 1; i < k; i++)
    //     {
    //         auto p = pq.top();
    //         pq.pop();

    //         //AFTER POPPING, WE'LL PUSH NEXT ELEMENT OF THE ROW IN THE HEAP
    //         if (p.second + 1 < n)
    //             pq.push({p.first, p.second + 1});
    //     }
    //     // ON THE k'th ITERATION, pq.top() will be our answer.
    //     return mat[pq.top().first][pq.top().second];
    // }

    //My solution On^2logn^2 time On^2 space
    // int kthSmallest(vector<vector<int>> &matrix, int k)
    // {
    //     vector<int> ans;

    //     for (vector<int> v : matrix)
    //     {
    //         for (int e : v)
    //         {
    //             ans.push_back(e);
    //         }
    //     }

    //     sort(ans.begin(), ans.end());

    //     return ans[k - 1];
    // }
};
// @lc code=end
