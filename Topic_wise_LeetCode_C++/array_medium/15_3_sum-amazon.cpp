/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    //Striver solutions
    // * Brute force On^3logm time On space:
    // `three nested loops and store in set in sorted order`
    // * Better On^2logm (insertion time in set) time logm (set)+n (hashmap) space:
    // `two loops for a and b and for c check if -(a+b) exits in hash map after decreasing count of a and b, if it exits then sort them and insert in set so that only unique are there`
    // * Optimal using two pointer two sum On^2 time Om ans space

    // a constant initially at index 0 find b+c = -a, low at right of a and hi pointer at rightmost,
    // get b+c and move b or c as per -a, if found add them to ans and move both lo and high
    // . Ignore duplicates for a,b,c. Stop when lo crosses hi
    // Code similar as my solution

    vector<vector<int>> threeSum(vector<int> &num)
    {
        vector<vector<int>> res;
        sort(num.begin(), num.end());

        // moves for a
        for (int i = 0; i < (int)(num.size()) - 2; i++)
        {

            if (i == 0 || (i > 0 && num[i] != num[i - 1]))
            {

                int lo = i + 1, hi = (int)(num.size()) - 1, sum = 0 - num[i];

                while (lo < hi)
                {
                    if (num[lo] + num[hi] == sum)
                    {

                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[lo]);
                        temp.push_back(num[hi]);
                        res.push_back(temp);

                        while (lo < hi && num[lo] == num[lo + 1])
                            lo++;
                        while (lo < hi && num[hi] == num[hi - 1])
                            hi--;

                        lo++;
                        hi--;
                    }
                    else if (num[lo] + num[hi] < sum)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        return res;
    }
    //My solution On2 time On space Like 4 sum
    // vector<vector<int>> threeSum(vector<int> &nums)
    // {
    //     if (nums.size() < 3)
    //         return {};
    //     sort(nums.begin(), nums.end());
    //     vector<vector<int>> ans;
    //     for (int i = 0; i <= nums.size() - 3; i++)
    //     {
    //         int target = -(nums[i]);
    //         int front = i + 1;
    //         int back = nums.size() - 1;
    //         while (front < back)
    //         {
    //             int sum = nums[front] + nums[back];
    //             if (sum < target)
    //             {
    //                 front++;
    //             }
    //             else if (sum > target)
    //             {
    //                 back--;
    //             }
    //             else
    //             {
    //                 vector<int> triplet;
    //                 triplet.push_back(nums[i]);
    //                 triplet.push_back(nums[front]);
    //                 triplet.push_back(nums[back]);
    //                 ans.push_back(triplet);

    //                 while (front < back && nums[front] == triplet[1])
    //                     front++;
    //                 while (front < back && nums[back] == triplet[2])
    //                     back--;
    //             }

    //             while (i + 1 <= nums.size() - 3 && nums[i] == nums[i + 1])
    //                 i++;
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end
