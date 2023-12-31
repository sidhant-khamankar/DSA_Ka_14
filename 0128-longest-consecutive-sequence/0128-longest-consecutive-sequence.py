# class Solution:
#     def longestConsecutive(self, nums: List[int]) -> int:
        
#         # O(n) time O(1) space
#         # drop duplicates
#         # sort
#         # check for consecutiveness
#         # if consicutiveness breaks or it is last second element, then update maxi
        
#         nums = list(set(nums))
#         if len(nums) == 0:
#             return 0
        
#         nums.sort()
#         curr = 1
#         maxi = 1
#         for i in range(0, len(nums)-1):
            
#             if i == len(nums)-2:
#                 if (nums[i+1]==nums[i]+1):
#                     curr += 1
#                 maxi = max(curr, maxi) 
#             elif nums[i+1] == nums[i] + 1:
#                 curr += 1
#             else:
#                 maxi = max(curr, maxi)
#                 curr = 1
        
#         return maxi
    
# Neetcode solution
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        longest = 0

        for n in nums:
            # check if its the start of a sequence
            if (n - 1) not in numSet:
                length = 1
                while (n + length) in numSet:
                    length += 1
                longest = max(length, longest)
        return longest

    