/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
/*
    Given airline tickets, find valid itinerary (use all tickets once)
    Ex. tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
        output = ["JFK","MUC","LHR","SFO","SJC"]
    Greedy DFS, build route backwards when retreating, merge cycles into main path
    Time: O(E log (E / V)) -> E = No. of flights, V = No. of airports, sorting
    Space: O(V + E) -> store No. of airports & No. of flights in hash map

    Multiset sorts ascendically so last dfs call will take place with highest lexical order

    Did not get
    Neetcode solution
*/

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, multiset<string>> m;
        for (int i = 0; i < tickets.size(); i++)
        {
            m[tickets[i][0]].insert(tickets[i][1]);
        }

        vector<string> result;
        dfs(m, "JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }

private:
    void dfs(unordered_map<string, multiset<string>> &m,
             string airport, vector<string> &result)
    {

        while (!m[airport].empty())
        {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            dfs(m, next, result);
        }

        result.push_back(airport);
    }
};
// @lc code=end
