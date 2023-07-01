/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 */

// @lc code=start
class Solution
{

    // did not get

    // Techdose solution
    // Rolling hash Ologn (binary search) * N (sliding window) * logn ( map insertiona and search) time

    int p = 10000007;
    vector<int> roll;

    bool match(string s, int len, int size, string &ans)
    {
        unordered_map<int, vector<int>> m; //Key->hashValue...Value->starting index of substring
        int hash = 0;                      //curr window hash or hash of first window of size mid
        for (int i = 0; i < size; ++i)
            hash = (hash * 26 + (s[i] - 'a')) % p;

        m[hash].push_back(0);
        //Rolling hash (sliding window)
        for (int j = size; j < len; ++j)
        {
            hash = ((hash - roll[size - 1] * (s[j - size] - 'a')) % p + p) % p; // why +p? // maybe due to (a-b)%m = ((a%m) - (b%m) + m)%m and m%m = 0
            hash = (hash * 26 + (s[j] - 'a')) % p;
            if (m.find(hash) != m.end()) //find O1 time
            {
                for (auto start : m[hash])
                {
                    string temp = s.substr(start, size);
                    string curr = s.substr(j - size + 1, size);
                    if (temp.compare(curr) == 0)
                    {
                        ans = temp;
                        return true;
                    }
                }
            }
            m[hash].push_back(j - size + 1);
        }
        return false;
    }

public:
    string longestDupSubstring(string S)
    {
        ios_base::sync_with_stdio(false); //faster input output
        cin.tie(NULL);

        int len = S.size();
        if (len == 0)
            return "";

        //Store all rolling hash values
        roll.resize(len); //Allocating fixed space to array
        roll[0] = 1;      //Since 26^0 = 1
        for (int i = 1; i < len; ++i)
            roll[i] = (26 * roll[i - 1]) % p;

        int low = 1, high = len, mid; // binary search
        string ans = "", temp;
        while (low <= high)
        {
            temp = "";
            mid = low + (high - low) / 2;         //to prevent overflow
            bool flag = match(S, len, mid, temp); //utility function
            if (flag)                             //matched
            {
                if (temp.size() > ans.size())
                    ans = temp;
                low = mid + 1; //increase mid
            }
            else
                high = mid - 1; // decrease mid
        }
        return ans;
    }
};
// @lc code=end
