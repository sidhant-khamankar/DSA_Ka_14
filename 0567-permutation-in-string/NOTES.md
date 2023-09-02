# Leetcode solution
# Did not get
# Neetcode solution
​
```
class Solution
{
public:
// did not get
// Neetcode solution On*26 time On*26 space
bool isEmpty(vector<int> arr)
{
for (int i = 0; i < arr.size(); i++)
{
if (arr[i] != 0)
return false;
}
return true;
}
bool checkInclusion(string s1, string s2)
{
if (s2.size() < s1.size())
return false;
vector<int> arr(26);
// add the values to the hash array
for (int i = 0; i < s1.size(); i++)
{
arr[s1[i] - 'a']++;
}
int i = 0;
int j = 0;
// point j to it's position
for (; j < s1.size(); j++)
{
arr[s2[j] - 'a']--;
}
j--;
if (isEmpty(arr))
return true;
while (j < s2.size())
{
arr[s2[i] - 'a']++;
i++;
j++;
if (j < s2.size())
arr[s2[j] - 'a']--;
if (isEmpty(arr))
return true;
}
return isEmpty(arr);
}
};
```