/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start

// Coding simplified gfg solution Oklogk+O(n-k)*logk
class KthLargest
{
public:
    int cap;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int> &nums)
    {
        cap = k;

        sort(nums.begin(), nums.end(), greater<int>());

        if (nums.size() >= k)
        {
            for (int i = 0; i < k; i++)
                pq.push(nums[i]);
        }
        else
        {
            for (int i = 0; i < nums.size(); i++)
                pq.push(nums[i]);
        }
    }

    int add(int val)
    {
        if (pq.size() < cap)
        {
            pq.push(val);
            return pq.top();
        }
        else if (val > pq.top())
        {
            pq.pop();
            pq.push(val);
            return pq.top();
        }
        else
        {
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
