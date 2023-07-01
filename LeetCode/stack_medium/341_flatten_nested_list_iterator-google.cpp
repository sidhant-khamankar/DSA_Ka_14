/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// My solution , Algorithms made easy On time On space
class NestedIterator
{
public:
    int ind = 0;

    vector<int> flattened;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        recur(nestedList, flattened);
    }

    void recur(vector<NestedInteger> nestedList, vector<int> &flattened)
    {
        for (NestedInteger i : nestedList)
        {
            if (i.isInteger())
            {
                flattened.push_back(i.getInteger());
            }
            else
            {
                recur(i.getList(), flattened);
            }
        }
    }
    int next()
    {
        return flattened[ind++];
    }

    bool hasNext()
    {
        if (ind < flattened.size())
            return true;
        else
            return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end
