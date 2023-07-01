/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution
{
public:
    // Neetcode solution simpler On time On space
    // class Solution:
    //    def sorted Squares(self,nums:List[int])->List[int]:
    //         res= []
    //         1,r= 0,len(nums)-1
    //         while 1<=r:
    //             if nums[1]*nums[1] > nums[r]*nums[r]:
    //                 res.append(nums[1]*nums[1])
    //                 1+=1
    //             else:
    //                 res.append(nums[r]*nums[r])
    //                 r==1
    //         return res[::-1] #reverse
    // My solution On time On space
    vector<int> sortedSquares(vector<int> &nums)
    {
        // 12.42
        int pIndex = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                nums[i] = -1 * nums[i];
                pIndex = i;
            }
        }

        vector<int> ans;
        if (pIndex == -1)
        {

            for (int e : nums)
            {
                ans.push_back(e * e);
            }
        }

        else if (pIndex + 1 == nums.size())
        {
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                ans.push_back(nums[i] * nums[i]);
            }
        }

        else
        {
            int nIndex = pIndex;
            pIndex++;

            while (nIndex >= 0 || pIndex < nums.size())
            {
                if (pIndex == nums.size())
                {
                    ans.push_back(nums[nIndex] * nums[nIndex]);
                    nIndex--;
                }
                else if (nIndex == -1)
                {
                    ans.push_back(nums[pIndex] * nums[pIndex]);
                    pIndex++;
                }

                else if (nums[nIndex] <= nums[pIndex])
                {
                    ans.push_back(nums[nIndex] * nums[nIndex]);
                    nIndex--;
                }

                else if (nums[nIndex] > nums[pIndex])
                {
                    ans.push_back(nums[pIndex] * nums[pIndex]);
                    pIndex++;
                }
            }
        }

        return ans;
    }
};
// @lc code=end
