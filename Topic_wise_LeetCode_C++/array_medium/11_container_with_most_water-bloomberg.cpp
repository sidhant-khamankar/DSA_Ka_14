/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    // My solution On time O1 space two pointer
    // Neetcode solution, Leetcode solution like my solution
    //
    //     How does this approach work?

    // Initially we consider the area constituting the exterior most lines.
    // Now, to maximize the area, we need to consider the area
    // between the lines of larger lengths. If we try to move the pointer
    // at the longer line inwards, we won't gain any increase in area,
    // since it is limited by the shorter line. But moving the shorter
    // line's pointer could turn out to be beneficial, as per the same
    // argument, despite the reduction in the width. This is done since a
    // relatively longer line obtained by moving the shorter line's pointer
    // might overcome the reduction in area caused by the width reduction.
    int maxArea(vector<int> &height)
    {
        int low = 0;
        int high = height.size() - 1;

        int maxi_area = INT_MIN;

        while (low < high)
        {
            maxi_area = max(maxi_area, (high - low) * min(height[low], height[high]));
            if (height[low] <= height[high])
                low++;
            else
                high--;
        }

        return maxi_area;
    }
};
// @lc code=end
