/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    // did not get
    // Neetcode solution, similar leetcode solution Os+t time Os+t space
    string minWindow(string s, string t, string ans = "")
    {

        if (t == "")
            return "";

        // t and s dictionary
        unordered_map<char, int> countT, window;

        // t dictionary
        for (char c : t)
            countT[c]++;

        int have = 0, need = countT.size();
        // result position
        vector<int> res = {-1,
                           -1};

        // result length
        int resLen = INT_MAX;

        // start position
        int l = 0;

        // traverse s string
        for (int r = 0; r < s.size(); r++)
        {
            char c = s[r];
            window[c]++;

            // check if c is present in t's dictionary and if its occurrence is equal in both dictionaries
            if (countT.find(c) != countT.end() && window[c] == countT[c])
            {
                have += 1;
            }

            // all characters of t are present in current s substring
            while (have == need)
            {
                // update our result
                if ((r - l + 1) < resLen)
                {
                    res[0] = l;
                    res[1] = r;
                    resLen = r - l + 1;
                }
                // pop from the left of our window
                window[s[l]] -= 1;

                // check if s[l] is present in t's dictionary and if its occurrence is less in s's dictionary
                if (countT.find(s[l]) != countT.end() && window[s[l]] < countT[s[l]])
                {
                    have -= 1;
                }

                // popped from left
                l += 1;
            }
        }

        int start = res[0];
        int end = res[1];
        if (resLen != INT_MAX)
            return s.substr(start, end - start + 1);
        else
            return "";
    }
};
// @lc code=end
