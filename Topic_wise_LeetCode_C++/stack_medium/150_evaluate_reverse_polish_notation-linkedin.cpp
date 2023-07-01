/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
    // My solution On time On space
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (string s : tokens)
        {

            if (s.size() == 1 && s[0] < '0')
            {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                // cout<<"first: "<<first<<" "<<"second: "<<second<<endl;
                if (s[0] == '*')
                    st.push(first * second);
                else if (s[0] == '+')
                    st.push(second + first);
                else if (s[0] == '-')
                    st.push(second - first);
                else if (s[0] == '/')
                {
                    // cout<<first/second;
                    st.push(second / first);
                }
            }
            else
            {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
    // Coding decoded solution On time
    // class Solution
    // {
    //     // TC  : O(n)

    // public
    //     int evalRPN(String[] tokens)
    //     {
    //         Stack<String> st = new Stack<>();

    //         for (String el : tokens)
    //         {
    //             if (isOperator(el))
    //             {

    //                 int el2 = Integer.parseInt(st.pop());
    //                 int el1 = Integer.parseInt(st.pop());
    //                 int ans = 0;

    //                 if (el.equals("*"))
    //                 {
    //                     ans = el1 * el2;
    //                 }
    //                 else if (el.equals("/"))
    //                 {
    //                     ans = el1 / el2;
    //                 }
    //                 else if (el.equals("+"))
    //                 {
    //                     ans = el1 + el2;
    //                 }
    //                 else if (el.equals("-"))
    //                 {
    //                     ans = el1 - el2;
    //                 }
    //                 st.push(ans + "");
    //             }
    //             else
    //             {
    //                 // operand
    //                 st.push(el);
    //             }
    //         }

    //         return Integer.parseInt(st.peek());
    //     }

    // private
    //     boolean isOperator(String el)
    //     {
    //         if (el.equals("*") || el.equals("+") || el.equals("-") || el.equals("/"))
    //         {
    //             return true;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }
    // }
};
// @lc code=end
