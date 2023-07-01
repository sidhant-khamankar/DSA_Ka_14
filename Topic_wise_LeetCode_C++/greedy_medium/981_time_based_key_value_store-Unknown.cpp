/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap
{
    // TLE on 44/48 TCs
    // Neetcode, leetcode solution M set calls, N get calls, L key length
    // set function O(L * M * logM) time for m calls, hashing L length, balanced binary tree logM
    // Om.l space
    // get function find: l.logM, binary search LogM, N calls
    // On.(l.logM + logM)
private:
    unordered_map<string, vector<pair<int, string>>> m;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        m[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (m.find(key) == m.end())
        {
            return "";
        }

        int low = 0;
        int high = m[key].size() - 1;

        string res = "";
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (m[key][mid].first <= timestamp)
            {
                res = m[key][mid].second;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
