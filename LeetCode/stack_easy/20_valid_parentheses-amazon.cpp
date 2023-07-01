/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start

// #Leetcode solution
// Like my solution On time On space
// java code
// class Solution
// {
//     // Hash table that takes care of the mappings.
// private
//     HashMap<Character, Character> mappings;

//     // Initialize hash map with mappings. This simply makes the code easier to read.
// public
//     Solution()
//     {
//         this.mappings = new HashMap<Character, Character>();
//         this.mappings.put(')', '(');
//         this.mappings.put('}', '{');
//         this.mappings.put(']', '[');
//     }

// public
//     boolean isValid(String s)
//     {

//         // Initialize a stack to be used in the algorithm.
//         Stack<Character> stack = new Stack<Character>();

//         for (int i = 0; i < s.length(); i++)
//         {
//             char c = s.charAt(i);

//             // If the current character is a closing bracket.
//             if (this.mappings.containsKey(c))
//             {

//                 // Get the top element of the stack. If the stack is empty, set a dummy value of '#'
//                 char topElement = stack.empty() ? '#' : stack.pop();

//                 // If the mapping for this bracket doesn't match the stack's top element, return false.
//                 if (topElement != this.mappings.get(c))
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 // If it was an opening bracket, push to the stack.
//                 stack.push(c);
//             }
//         }

//         // If the stack still contains elements, then it is an invalid expression.
//         return stack.isEmpty();
//     }
// }

// #Apna College
//     same as leetcode solution

// My solution On time On space
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> ch;
        stack<char> close;

        if (s.size() == 1)
            return false;

        map<char, char> mp;
        mp.insert({'(', ')'});
        mp.insert({'[', ']'});
        mp.insert({'{', '}'});

        for (char c : s)
            ch.push(c);

        while (!ch.empty())
        {
            if (close.empty()) // if second stack is empty, initially ch stack's top is guranteed to be closing brackets
            {
                close.push(ch.top()); //add closing bracket
                ch.pop();             //remove closing bracket
            }
            else
            {
                char currc = close.empty() ? '0' : close.top();       //closing bracket
                char curro = ch.top();                                // opening bracket
                ch.pop();                                             //remove opening bracket
                if (mp.find(curro) != mp.end() && mp[curro] == currc) //if opening and closing brackets belongs to same set
                    close.pop();                                      //remove closing bracket
                else
                    close.push(curro);
            }
        }

        if (close.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end
