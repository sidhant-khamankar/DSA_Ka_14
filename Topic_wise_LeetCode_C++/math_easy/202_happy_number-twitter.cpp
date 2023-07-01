/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start

// did not get

// leetcode Solution
// hashing Ologn time On space
// class Solution {

//     private int getNext(int n) {
//         int totalSum = 0;
//         while (n > 0) {
//             int d = n % 10;
//             n = n / 10;
//             totalSum += d * d;
//         }
//         return totalSum;
//     }

//     public boolean isHappy(int n) {
//         Set<Integer> seen = new HashSet<>();
//         while (n != 1 && !seen.contains(n)) {
//             seen.add(n);
//             n = getNext(n);
//         }
//         return n == 1;
//     }
// }

// hashset tech dose solution Ologn time On space
class Solution
{
public:
    bool isHappy(int n)
    {

        set<int> myset;
        int val;
        int index;

        while (1)
        {
            val = 0;
            while (n)
            {
                index = n % 10;
                val += index * index;
                n /= 10;
            }
            if (val == 1)
                return true;
            else if (myset.find(val) != myset.end())
                return false;

            myset.insert(val);
            n = val;
        }
        return false;
    }
};

//hare and tortoise Ologn time O1 space
// class Solution
// {
// public:
//     int getNext(int n)
//     {
//         int totalSum = 0;
//         while (n > 0)
//         {
//             int d = n % 10;
//             n = n / 10;
//             totalSum += d * d;
//         }
//         return totalSum;
//     }

//     bool isHappy(int n)
//     {
//         int slowRunner = n;
//         int fastRunner = getNext(n);
//         while (fastRunner != 1 && slowRunner != fastRunner)
//         {
//             slowRunner = getNext(slowRunner);
//             fastRunner = getNext(getNext(fastRunner));
//         }
//         return fastRunner == 1;
//     }
// };

// Hardcoded not for interview solution Ologn time O1 space
// class Solution
// {

// public
//     int getNext(int n)
//     {
//         int totalSum = 0;
//         while (n > 0)
//         {
//             int d = n % 10;
//             n = n / 10;
//             totalSum += d * d;
//         }
//         return totalSum;
//     }

// public
//     boolean isHappy(int n)
//     {
//         while (n != 1 && n != 4)
//         {
//             n = getNext(n);
//         }
//         return n == 1;
//     }
// }

// @lc code=end
