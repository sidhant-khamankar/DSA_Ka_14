# Striver Solution
* Naive Onlogn+n time :
Sort the array and check consecutive sequence
* Hashset On set+On check+On count time On space (unordered_set cpp O1 time)
insert all elements in hashset
iterate and check if element-1 exists or not, if it exists pass else move to element +1 and check if it exits and continue likewise else quit
update longest
logic : start from starting (minimal number)
code like leetcode solution
# Leetcode solution
Hashset On time On space
```
class Solution {
public int longestConsecutive(int[] nums) {
Set<Integer> num_set = new HashSet<Integer>();
for (int num : nums) {
num_set.add(num);
}
​
int longestStreak = 0;
​
for (int num : num_set) {
if (!num_set.contains(num-1)) {
int currentNum = num;
int currentStreak = 1;
​
while (num_set.contains(currentNum+1)) {
currentNum += 1;
currentStreak += 1;
}
​
longestStreak = Math.max(longestStreak, currentStreak);
}
}
​
return longestStreak;
}
}
```
# My solution
​