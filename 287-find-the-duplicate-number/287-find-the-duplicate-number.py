# My solution
# 1. Maintain Set
# 2. Sorting

# Neetcode solution
# Tricky problem coverts to find loop in linked list problem
# slow and fast method

# Tortoise method slow and fast pointer
# image - https://leetcode.com/problems/find-the-duplicate-number/discuss/704693/Python-2-solutions%3A-Linked-List-Cycle-O(n)-and-BS-O(n-log-n)-explained
# slow 1 step, fast 2 steps untill they meet 
# put slow pointer at starting and move both by 1 step untill they meet at duplicate number
# O(n) time O(1) space
class Solution:
    def findDuplicate(self, nums):
        slow, fast = nums[0], nums[0]
        while True:
            slow, fast = nums[slow], nums[nums[fast]]
            if slow == fast: 
                break
        
        slow = nums[0];
        while slow != fast:
            slow, fast = nums[slow], nums[fast]
        return slow

        