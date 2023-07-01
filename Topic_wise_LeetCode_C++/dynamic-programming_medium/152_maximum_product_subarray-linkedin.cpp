/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    //did not get
    // Coding ninjas gfg solution

    // Bruteforce On^2 time O1 space
    /* Returns the product of max product subarray.*/
    // int maxSubarrayProduct(int arr[], int n)
    // {
    //     // Initializing result
    //     int result = arr[0];

    //     for (int i = 0; i < n; i++)
    //     {
    //         int mul = arr[i];
    //         // traversing in current subarray
    //         for (int j = i + 1; j < n; j++)
    //         {
    //             // updating result every time
    //             // to keep an eye over the maximum product
    //             result = max(result, mul);
    //             mul *= arr[j];
    //         }
    //         // updating the result for (n-1)th index.
    //         result = max(result, mul);
    //     }
    //     return result;
    // }

    //Leetcode discuss Efficient On time O1 space
    int maxProduct(vector<int> &A)
    {
        int n = A.size();
        // store the result that is the max we have found so far
        int r = A[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number A[i]
        for (int i = 1, imax = r, imin = r; i < n; i++)
        {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if (A[i] < 0)
                swap(imax, imin);

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax = max(A[i], imax * A[i]);
            imin = min(A[i], imin * A[i]);

            // the newly computed max value is a candidate for our global result
            r = max(r, imax);
        }
        return r;
    }
};
// @lc code=end
