# did not get
​
# Neetcode solution
​
```
/*
* @lc app=leetcode id=739 lang=cpp
*
* [739] Daily Temperatures
*/
​
// @lc code=start
class Solution
{
public:
vector<int> dailyTemperatures(vector<int> &temperatures)
{
// did not get
// Neetcode solution On time On space
int n = temperatures.size();
​
// pair: [index, temp]
stack<pair<int, int>> stk;
vector<int> result(n, 0);
​
for (int i = 0; i < n; i++)
{
int currDay = i;
int currTemp = temperatures[i];
​
while (!stk.empty() && stk.top().second < currTemp)
{
int prevDay = stk.top().first;
int prevTemp = stk.top().second;
stk.pop();
​
result[prevDay] = currDay - prevDay;
}
​
stk.push({currDay, currTemp});
}
​
return result;
}
};
// @lc code=end
​
```