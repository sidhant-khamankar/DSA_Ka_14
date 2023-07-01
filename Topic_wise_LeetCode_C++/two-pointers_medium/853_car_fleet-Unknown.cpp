/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
class Solution
{
public:
    // 100\n[0,2,4]\n[4,2,1]
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        // did not get
        // Neetcode solution On time On space

        // class Solution:
        // def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        //     pair = [(p, s) for p, s in zip(position, speed)]
        //     pair.sort(reverse=True)
        //     stack = []
        //     for p, s in pair:  # Reverse Sorted Order
        //         stack.append((target - p) / s)
        //         if len(stack) >= 2 and stack[-1] <= stack[-2]:
        //             stack.pop()
        //     return len(stack)
        int n = position.size();

        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++)
        {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());

        double maxTime = 0.0;
        int result = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            double time = cars[i].second;
            if (time > maxTime)
            {
                maxTime = time;
                result++;
            }
        }

        return result;
    }
};
// @lc code=end
