/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start

// My solution On time On space
class MyStack
{
private:
    queue<int> q1;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
    }

    //["MyStack","push","push","push","pop","pop","pop","empty"]\n[[],[1],[2],[3],[],[],[],[]]

    /** Removes the element on top of the stack and returns that element. */
    int
    pop()
    {
        queue<int> q2;
        int temp = q1.back();
        int n = q1.size();
        for (int i = 1; i < n; ++i)
        {
            q2.push(q1.front());
            q1.pop();
        }

        if (q2.size() == 0)
        {
            cout << "q1: " << q1.back() << endl;
            q1.pop();
        }
        else
        {
            cout << "q2: " << q2.back() << endl;
            q1.swap(q2);
        }
        return temp;
    }

    /** Get the top element. */
    int top()
    {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
