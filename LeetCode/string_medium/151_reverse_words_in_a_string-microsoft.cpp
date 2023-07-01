/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start

// gfg solution On time On space
// void printRev(string str)
// {
//     // Stack to store each
//     // word of the string
//     stack<string> st;

//     // Store the whole string
//     // in string stream
//     stringstream ss(str);

//     string temp;
//     while (getline(ss, temp, ' '))
//     {

//         // Push each word of the
//         // string into the stack
//         st.push(temp);
//     }

//     // Print the string in reverse
//     // order of the words
//     while (!st.empty())
//     {
//         cout << st.top() << " ";
//         st.pop();
//     }
// }

// My solution On time On space
class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        for (int i = 0; i < s.size();)
        {
            string w;
            int j = i;
            while (j < s.size() && s[j] != ' ')
            {
                w += s[j];
                j++;
            }
            if (w.size() != 0)
                words.push_back(w);
            i = j + 1;
        }

        reverse(words.begin(), words.end());
        string ans;
        for (int i = 0; i < words.size(); i++)
        {
            if (i == words.size() - 1)
                ans += words[i];
            else
                ans += words[i] + " ";
        }

        return ans;
    }
};
// @lc code=end
