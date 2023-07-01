/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    //Leetcode solution
    //Recursion brute force O2^n time On space
    // class Solution
    // {
    // public:
    //     bool wordBreak(string s, vector<string> &wordDict)
    //     {
    //         set<string> word_set(wordDict.begin(), wordDict.end());
    //         return wordBreakRecur(s, word_set, 0);
    //     }

    //     bool wordBreakRecur(string &s, set<string> &word_set, int start)
    //     {
    //         if (start == s.length())
    //         {
    //             return true;
    //         }
    //         for (int end = start + 1; end <= s.length(); end++)
    //         {
    //             if (word_set.find(s.substr(start, end - start)) != word_set.end() and
    //                 wordBreakRecur(s, word_set, end))
    //             {
    //                 return true;
    //             }
    //         }
    //         return false;
    //     }
    // };

    //Memoization On^3 time On space
    // class Solution
    // {
    // public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        set<string> word_set(wordDict.begin(), wordDict.end());
        // In the memo table, -1 stands for the state not yet reached,
        // 0 for false and 1 for true
        vector<int> memo(s.length(), -1);
        return wordBreakMemo(s, word_set, 0, memo);
    }

    bool wordBreakMemo(string &s, set<string> &word_set, int start, vector<int> &memo)
    {
        if (start == s.length())
        {
            return true;
        }
        if (memo[start] != -1)
        {
            return memo[start];
        }
        for (int end = start + 1; end <= s.length(); end++)
        {
            //susbstr takes starting position and length of substring
            if (word_set.find(s.substr(start, end - start)) != word_set.end() and
                wordBreakMemo(s, word_set, end, memo))
            {
                return memo[start] = true;
            }
        }
        return memo[start] = false;
    }
    // };

    //bfs On^3 time On space
    // class Solution
    // {
    // public:
    //     bool wordBreak(string s, vector<string> &wordDict)
    //     {
    //         set<string> word_set(wordDict.begin(), wordDict.end());
    //         queue<int> q;
    //         vector<bool> visited(s.length(), false);
    //         q.push(0);
    //         while (!q.empty())
    //         {
    //             int start = q.front();
    //             q.pop();
    //             if (visited[start])
    //             {
    //                 continue;
    //             }
    //             for (int end = start + 1; end <= s.length(); end++)
    //             {
    //                 if (word_set.find(s.substr(start, end - start)) !=
    //                     word_set.end())
    //                 {
    //                     q.push(end);
    //                     if (end == s.length())
    //                     {
    //                         return true;
    //                     }
    //                 }
    //             }
    //             visited[start] = true;
    //         }
    //         return false;
    //     }
    // };

    //top down dp On^3 time On space
    // class Solution
    // {
    // public:
    //     bool wordBreak(string s, vector<string> &wordDict)
    //     {
    //         set<string> word_set(wordDict.begin(), wordDict.end());
    //         vector<bool> dp(s.length() + 1);
    //         dp[0] = true;

    //         for (int i = 1; i <= s.length(); i++)
    //         {
    //             for (int j = 0; j < i; j++)
    //             {
    //                 if (dp[j] and
    //                     word_set.find(s.substr(j, i - j)) != word_set.end())
    //                 {
    //                     dp[i] = true;
    //                     break;
    //                 }
    //             }
    //         }
    //         return dp[s.length()];
    //     }
    // };

    // Tech dose gfg Solution
    // Recursion
    /* A utility function to check whether a word is
  present in dictionary or not. An array of strings
  is used for dictionary.  Using array of strings for
  dictionary is definitely not a good idea. We have
  used for simplicity of the program*/
    // int dictionaryContains(string word)
    // {
    //     string dictionary[] = {"mobile", "samsung", "sam", "sung",
    //                            "man", "mango", "icecream", "and",
    //                            "go", "i", "like", "ice", "cream"};
    //     int size = sizeof(dictionary) / sizeof(dictionary[0]);
    //     for (int i = 0; i < size; i++)
    //         if (dictionary[i].compare(word) == 0)
    //             return true;
    //     return false;
    // }

    // // returns true if string can be segmented into space
    // // separated words, otherwise returns false
    // bool wordBreak(string str)
    // {
    //     int size = str.size();

    //     // Base case
    //     if (size == 0)
    //         return true;

    //     // Try all prefixes of lengths from 1 to size
    //     for (int i = 1; i <= size; i++)
    //     {
    //         // The parameter for dictionaryContains is
    //         // str.substr(0, i) which is prefix (of input
    //         // string) of length 'i'. We first check whether
    //         // current prefix is in  dictionary. Then we
    //         // recursively check for remaining string
    //         // str.substr(i, size-i) which is suffix of
    //         // length size-i
    //         if (dictionaryContains(str.substr(0, i)) &&
    //             wordBreak(str.substr(i, size - i)))
    //             return true;
    //     }

    //     // If we have tried all prefixes and
    //     // none of them worked
    //     return false;
    // }

    // dp On^2 with hashset
    /* A utility function to check whether a word is present in dictionary or not.
  An array of strings is used for dictionary.  Using array of strings for
  dictionary is definitely not a good idea. We have used for simplicity of
  the program*/
    // int dictionaryContains(string word)
    // {
    //     string dictionary[] = {"mobile", "samsung", "sam", "sung", "man", "mango",
    //                            "icecream", "and", "go", "i", "like", "ice", "cream"};
    //     int size = sizeof(dictionary) / sizeof(dictionary[0]);
    //     for (int i = 0; i < size; i++)
    //         if (dictionary[i].compare(word) == 0)
    //             return true;
    //     return false;
    // }

    // // Returns true if string can be segmented into space separated
    // // words, otherwise returns false
    // bool wordBreak(string str)
    // {
    //     int size = str.size();
    //     if (size == 0)
    //         return true;

    //     // Create the DP table to store results of subroblems. The value wb[i]
    //     // will be true if str[0..i-1] can be segmented into dictionary words,
    //     // otherwise false.
    //     bool wb[size + 1];
    //     memset(wb, 0, sizeof(wb)); // Initialize all values as false.

    //     for (int i = 1; i <= size; i++)
    //     {
    //         // if wb[i] is false, then check if current prefix can make it true.
    //         // Current prefix is "str.substr(0, i)"
    //         if (wb[i] == false && dictionaryContains(str.substr(0, i)))
    //             wb[i] = true;

    //         // wb[i] is true, then check for all substrings starting from
    //         // (i+1)th character and store their results.
    //         if (wb[i] == true)
    //         {
    //             // If we reached the last prefix
    //             if (i == size)
    //                 return true;

    //             for (int j = i + 1; j <= size; j++)
    //             {
    //                 // Update wb[j] if it is false and can be updated
    //                 // Note the parameter passed to dictionaryContains() is
    //                 // substring starting from index 'i' and length 'j-i'
    //                 if (wb[j] == false && dictionaryContains(str.substr(i, j - i)))
    //                     wb[j] = true;

    //                 // If we reached the last character
    //                 if (j == size && wb[j] == true)
    //                     return true;
    //             }
    //         }
    //     }

    //     /* Uncomment these lines to print DP table "wb[]"
    //  for (int i = 1; i <= size; i++)
    //     cout << " " << wb[i]; */

    //     // If we have tried all prefixes and none of them worked
    //     return false;
    // }

    //My solution MCM variation On^3 substr  time On^2 space
    // bool recur(int i, int j, string s, unordered_set<string> &dict, vector<vector<int>> &dp)
    // {
    //     if (j - i + 1 == 0)
    //         return true;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     string t = s.substr(i, j - i + 1);

    //     if (j - i + 1 == 1 && dict.find(t) == dict.end())
    //         return dp[i][j] = 0;
    //     else if (dict.find(t) != dict.end())
    //     {
    //         return dp[i][j] = 1;
    //     }

    //     for (int k = i; k < j; k++)
    //     {

    //         if (recur(0, k, s, dict, dp) && recur(k + 1, j, s, dict, dp))
    //         {
    //             dp[i][k] = 1;
    //             dp[k + 1][j] = 1;
    //             return dp[i][j] = 1;
    //         }
    //     }
    //     return dp[i][j] = 0;
    // }
    // bool wordBreak(string s, vector<string> &wordDict)
    // {
    //     unordered_set<string> dict;
    //     for (string s : wordDict)
    //         dict.insert(s);

    //     vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
    //     return recur(0, s.size() - 1, s, dict, dp);
    // }
};
// @lc code=end
