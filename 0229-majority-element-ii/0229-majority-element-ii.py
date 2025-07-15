# neetcode solution
'''
boyer moore voting algorithm
ans size atmost 2
time O(n), space O(1)
```
'''
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        n = len(nums)
        num1 = num2 = -1
        cnt1 = cnt2 = 0

        for num in nums:
            if num == num1:
                cnt1 += 1
            elif num == num2:
                cnt2 += 1
            elif cnt1 == 0:
                cnt1 = 1
                num1 = num
            elif cnt2 == 0:
                cnt2 = 1
                num2 = num
            else:
                cnt1 -= 1
                cnt2 -= 1
        
        cnt1 = cnt2 = 0
        for num in nums:
            if num == num1:
                cnt1 += 1
            elif num == num2:
                cnt2 += 1
        
        res = []
        if cnt1 > n // 3:
            res.append(num1)
        if cnt2 > n // 3:
            res.append(num2)
        
        return res
'''
```
'''
# Striver Solution
'''
* Bruteforce On^2 time O1 space:
pick one element and check its occurences if its greater than n/3 or not, then repeat for other elements
* Better :
Use Hashmap On or Onlogn if map and On^2 for unordered map time On space- My solution 
* Bayer Moore Voting Algorithm On+On time O1 space
Cannot have more than 2 majority elements
```
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // Striver Solution Bayer Moore Voting Algorithm On+On time O1 space
        int sz = nums.size();
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
            else if (count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if (count1 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = count2 = 0;
        for (i = 0; i < sz; i++)
        {
            if (nums[i] == num1)
                count1++;
            else if (nums[i] == num2)
                count2++;
        }
        if (count1 > sz / 3)
            ans.push_back(num1);
        if (count2 > sz / 3)
            ans.push_back(num2);
        return ans;
    }
};
```
'''
# My solution 
'''
hashmap time O(n), space O(n)
python
```
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        freq = len(nums)//3
        map = dict()
        for i in nums:
            if i in map:
                map[i]+=1
            else:
                map[i] = 1
        
        ans = list()
        for key, val in map.items():
            if val > freq:
                ans.append(key)

        return ans
```
c++
```
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // Brute Onlogn if map and On^2 if unordered map time On space
        int max_times = nums.size() / 3;
        map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
            {
                m[nums[i]]++;
            }
            else
            {
                m[nums[i]] = 1;
            }
        }
        for (auto itr = m.begin(); itr != m.end(); itr++)
        {
            if ((itr->second > max_times))
                ans.emplace_back(itr->first);
        }

        return ans;
    }
};
```
'''