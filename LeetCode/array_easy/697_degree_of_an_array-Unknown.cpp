/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
class Solution
{
public:
    // Leetcode solution similar to my solution

    // class Solution
    // {
    // public
    //     int findShortestSubArray(int[] nums)
    //     {
    //         Map<Integer, Integer> left = new HashMap(),
    //                               right = new HashMap(), count = new HashMap();

    //         for (int i = 0; i < nums.length; i++)
    //         {
    //             int x = nums[i];
    //             if (left.get(x) == null)
    //                 left.put(x, i);
    //             right.put(x, i);
    //             count.put(x, count.getOrDefault(x, 0) + 1);
    //         }

    //         int ans = nums.length;
    //         int degree = Collections.max(count.values());
    //         for (int x : count.keySet())
    //         {
    //             if (count.get(x) == degree)
    //             {
    //                 ans = Math.min(ans, right.get(x) - left.get(x) + 1);
    //             }
    //         }
    //         return ans;
    //     }
    // }
    // nick white simiar solution first seen hashmap put if absent and update degree
    // get min distance i - first_seen[nums[i]] + 1;
    // for equal degree just get min_length = min(min_length, i - first_seen[nums[i]] + 1)

    // My solution On^2 time On space
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int e : nums)
        {
            mp[e]++;
        }

        int maxi = 1;

        for (pair<int, int> p : mp)
        {
            if (p.second > maxi)
            {
                maxi = p.second;
            }
        }

        vector<int> maxes;
        for (pair<int, int> p : mp)
        {
            if (p.second == maxi)
            {
                maxes.push_back(p.first);
            }
        }

        int ans = INT_MAX;

        for (int maxe : maxes)
        {
            int start = 0;
            int end = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == maxe)
                {
                    start = i;
                    break;
                }
            }

            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] == maxe)
                {
                    end = i;
                    break;
                }
            }
            ans = min(ans, end - start + 1);
        }
        return ans;
    }
};
// @lc code=end
