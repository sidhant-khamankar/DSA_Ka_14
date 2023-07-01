/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    // Leetcode solution, Techdose solution approach 2 On*k (k is longest string) time On*k space

    // class Solution
    // {
    // public
    //     List<List<String>> groupAnagrams(String[] strs)
    //     {
    //         if (strs.length == 0)
    //             return new ArrayList();
    //         Map<String, List> ans = new HashMap<String, List>();
    //         int[] count = new int[26];
    //         for (String s : strs)
    //         {
    //             Arrays.fill(count, 0);
    //             for (char c : s.toCharArray())
    //                 count[c - 'a']++;

    //             StringBuilder sb = new StringBuilder("");
    //             for (int i = 0; i < 26; i++)
    //             {
    //                 sb.append('#');
    //                 sb.append(count[i]);
    //             }
    //             String key = sb.toString();
    //             if (!ans.containsKey(key))
    //                 ans.put(key, new ArrayList());
    //             ans.get(key).add(s);
    //         }
    //         return new ArrayList(ans.values());
    //     }
    // }
    // My solution leetcode approach 1. Techdose solution On*klogk (k is longest string and sorting) time On*k space
    vector<vector<string>>
    groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (string s : strs)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            ans.push_back(itr->second);
        }

        return ans;
    }
};
// @lc code=end
