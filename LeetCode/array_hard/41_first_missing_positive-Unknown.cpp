/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution
{
public:
    // Rachit jain Leetcode discuss solution On time O1 space

    int firstMissingPositive(vector<int> A)
    {
        int n = A.size();
        for (int i = 0; i < n; ++i)
        {
            while (A[i] >= 1 && A[i] <= n && A[i] != A[A[i] - 1])
                swap(A[i], A[A[i] - 1]);
        }

        for (int i = 0; i < n; ++i)
            if (A[i] != i + 1)
                return i + 1;

        return n + 1;
    }

    // My solution Omax(A)) time On space
    // int firstMissingPositive(vector<int> &nums)
    // {
    //     unordered_set<int> st;
    //     int maxi = 1;
    //     for (int e : nums)
    //     {
    //         st.insert(e);
    //         if (e > maxi)
    //             maxi = e;
    //     }

    //     for (int i = 1; i <= maxi; i++)
    //     {
    //         if (st.find(i) == st.end())
    //             return i;
    //     }

    //     return maxi + 1;
    // }
};
// @lc code=end
