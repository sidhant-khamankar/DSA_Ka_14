/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    // did not get
    //Tech dose solution On time On space or use one array only so O1 space
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> output;
        if (n < 1)
            return output;

        int product = 1;
        for (int i = 0; i < n; ++i)
        {
            product *= nums[i];
            output.push_back(product);
        }

        //Traverse from right and update output array
        product = 1;
        for (int i = n - 1; i > 0; --i)
        {
            output[i] = output[i - 1] * product;
            product *= nums[i];
        }
        output[0] = product;

        return output;
    }
};
// @lc code=end
