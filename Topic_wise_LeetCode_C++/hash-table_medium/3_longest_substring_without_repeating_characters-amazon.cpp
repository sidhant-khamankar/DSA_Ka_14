/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Striver solution
        // *Naive On ^ 2 time On space :kadanes algorithm generate all substrings
        //*Better Sliding Window O2n time On space :set,l, r, len = 0. move right and check in set, if not found, len is l - r + 1 and push to set, if found in set,
        //remove from set and move l untill r's element is duplicate
        //* Optimal On(average case O1 unordered map but On in worst case) time On space :
        // Map to store indexes of duplicates move r, check map and if not found then put element, index in map and update length else if it already exists, move l to
        // map[element] + 1, then update index of element and move r, l moved so other duplicates indexes are left behind
        // On (average case O1 unordered map but On in worst case) time On space
        vector<int>
            mpp(256, -1);
        // or map character, int

        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while (right < n)
        {
            if (mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left); //check for abcabcbb and abcbacbb
            mpp[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;

        // My solution On^2 check every substring
        // if (s.size() == 0)
        //     return 0;

        // int len = 1;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     int j = i;
        //     unordered_map<char, int> mp;
        //     while (j + 1 < s.size() && s[j + 1] != s[j] && (mp[s[j + 1]] != 1 || mp[s[j]] != 1))
        //     {
        //         mp[s[j + 1]] = 1;
        //         mp[s[j]] = 1;
        //         j++;
        //     }
        //     len = max(len, j - i + 1);
        // }
        // return len;
    }
};
// @lc code=end
