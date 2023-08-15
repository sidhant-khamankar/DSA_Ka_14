# Neetcode, My Solution
​
```
/*
* @lc app=leetcode id=704 lang=cpp
*
* [704] Binary Search
*/
​
// @lc code=start
class Solution
{
public:
int search(vector<int> &nums, int target)
{
int start = 0;
int end = nums.size() - 1;
​
int mid;
​
// same as neetcode solution Ologn time O1 space
while (start <= end)
{
mid = start + (end - start) / 2;
if (nums[mid] == target)
{
break;
}
else if (target < nums[mid])
{
end--;
}
else if (target > nums[mid])
{
start++;
}
}
if (start > end)
{
return -1;
}
return mid;
}
};
// @lc code=end
​
```