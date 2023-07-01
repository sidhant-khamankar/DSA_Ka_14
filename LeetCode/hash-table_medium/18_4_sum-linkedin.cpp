/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // Did not get
        //Striver solution On^3 time O1 space
        vector<vector<int>> res;

        if (nums.empty())
            return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int target_2 = target - nums[j] - nums[i];
                int front = j + 1;
                int back = n - 1;
                while (front < back)
                {
                    int two_sum = nums[front] + nums[back];
                    if (two_sum < target_2)
                        front++;
                    else if (two_sum > target_2)
                        back--;
                    else
                    {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);

                        //processing duplicates from front
                        while (front < back && nums[front] == quadruplet[2])
                            ++front;
                        //processing duplicates from back
                        while (front < back && nums[back] == quadruplet[3])
                            --back;
                    }
                }
                //processing duplicates of j
                //2 2 2(reach here) 3
                while (j + 1 < n && nums[j + 1] == nums[j])
                    ++j;
            }
            //processing duplicates of i
            //2 2 2(reach here) 3
            while (i + 1 < n && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};
// @lc code=end
