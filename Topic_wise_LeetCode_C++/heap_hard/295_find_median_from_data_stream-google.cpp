/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder
{
public:
    // did not get

    //Apna college gfg solution Onlogn time On space
    priority_queue<double> s;

    // min heap to store the greater half elements
    priority_queue<double, vector<double>, greater<double>> g;

    double med;
    vector<double> arr;
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    // function to calculate med of stream
    void addNum(int num)
    {
        arr.push_back(num);
        if (arr.size() == 1)
        {
            med = arr[0];
            s.push(arr[0]);
            return;
        }

        // reading elements of stream one by one
        /*  At any time we try to make heaps balanced and
        their sizes differ by at-most 1. If heaps are
        balanced,then we declare median as average of
        min_heap_right.top() and max_heap_left.top()
        If heaps are unbalanced,then median is defined
        as the top element of heap of larger size  */

        double x = arr[arr.size() - 1];

        // case1(left side heap has more elements)
        if (s.size() > g.size())
        {
            if (x < med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);

            med = (s.top() + g.top()) / 2.0;
        }

        // case2(both heaps are balanced)
        else if (s.size() == g.size())
        {
            if (x < med)
            {
                s.push(x);
                med = (double)s.top();
            }
            else
            {
                g.push(x);
                med = (double)g.top();
            }
        }

        // case3(right side heap has more elements)
        else
        {
            if (x > med)
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);

            med = (s.top() + g.top()) / 2.0;
        }
    }

    double findMedian()
    {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
