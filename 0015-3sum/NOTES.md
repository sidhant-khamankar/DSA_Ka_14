# Striver solution
* Brute force On^3logm time On space:
`three nested loops and store in set in sorted order`
* Better On^2logm (insertion time in set) time logm (set)+n (hashmap) space:
`two loops for a and b and for c check if -(a+b) exits in hash map after decreasing count of a and b, if it exits then sort them and insert in set so that only unique are there`
* Optimal using two pointer two sum On^2 time Om ans space
```
a constant initially at index 0 find b+c = -a, low at right of a and hi pointer at rightmost,
get b+c and move b or c as per -a, if found add them to ans and move both lo and high
. Ignore duplicates for a,b,c. Stop when lo crosses hi
Code similar as my solution
```
```
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& num) {
vector<vector<int>> res;
sort(num.begin(), num.end());
// moves for a
for (int i = 0; i < (int)(num.size())-2; i++) {
if (i == 0 || (i > 0 && num[i] != num[i-1])) {
int lo = i+1, hi = (int)(num.size())-1, sum = 0 - num[i];
while (lo < hi) {
if (num[lo] + num[hi] == sum) {
vector<int> temp;
temp.push_back(num[i]);
temp.push_back(num[lo]);
temp.push_back(num[hi]);
res.push_back(temp);
while (lo < hi && num[lo] == num[lo+1]) lo++;
while (lo < hi && num[hi] == num[hi-1]) hi--;
lo++; hi--;
}
else if (num[lo] + num[hi] < sum) lo++;
else hi--;
}
}
}
return res;
}
};
```
# My solution
​
```
class Solution
{
public:
//My solution On2 time On space Like 4 sum
vector<vector<int>> threeSum(vector<int> &nums)
{