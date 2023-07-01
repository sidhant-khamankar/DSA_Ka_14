/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution
{
public:
    //did not get
    //Naresh Gupta solution TC - O(n^2), On^2 space
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> mp;
        for (int c : nums3)
            for (int d : nums4)
                mp[c + d] += 1;
        int count = 0;
        for (int a : nums1)
            for (int b : nums2)
                count += mp[-1 * (a + b)];
        return count;
    }

    // package main.cp.leetcode.december;

    // import java.util.HashMap;
    // import java.util.Map;

    //
    //  Naresh Gupta
    //  Detailed Video Explanation https://youtu.be/XHlA0KdvQBc?t=0
    // public
    //     class Day_17_454_4Sum_II
    //     {

    //         // Naresh Gupta solution TC - O(n^3), On space

    //         class Solution2
    //         {
    //         public
    //             int fourSumCount(int[] A, int[] B, int[] C, int[] D)
    //             {
    //                 Map<Integer, Integer> map = new HashMap();
    //                 for (int d : D)
    //                     map.put(d, map.getOrDefault(d, 0) + 1);
    //                 int count = 0;
    //                 for (int a : A)
    //                     for (int b : B)
    //                         for (int c : C)
    //                             count += map.getOrDefault(-(a + b + c), 0);
    //                 return count;
    //             }
    //         }

    //         // Naresh Gupta solution TC - O(n^4) On1 space

    //         class Solution3
    //         {
    //         public
    //             int fourSumCount(int[] A, int[] B, int[] C, int[] D)
    //             {
    //                 int count = 0;
    //                 for (int a : A)
    //                     for (int b : B)
    //                         for (int c : C)
    //                             for (int d : D)
    //                                 if (a + b + c + d == 0)
    //                                     count++;
    //                 return count;
    //             }
    //         }
    //     }
};
// @lc code=end
