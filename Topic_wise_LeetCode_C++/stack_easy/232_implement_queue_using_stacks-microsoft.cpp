/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start

//Leetcode solution like my solution
//Apna college
// * Using recursion for pop and return that element from bottom of stack

// My solution On time On space
class MyQueue
{
public:
    stack<int> st1;
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        st1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        stack<int> st2;
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st2.top();
        st2.pop();

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }

    /** Get the front element. */
    int peek()
    {
        stack<int> st2;
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int temp = st2.top();

        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return temp;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
