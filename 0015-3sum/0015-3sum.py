# did not get
# striver solution
# brute O(n^3 time)- three for loops and add into set to get unique triplets
# better O(n^2*logm) time - two for loops i and j, and put elements in between i and j inside hashset and check if hashset contains -(element at i + element at j)
# optimal O(n^2logn) time 
# O(ans) space
# one for loop and two pointer solution 
# neetcode solution

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        # O(nlogn)

        # O(n)
        for i, a in enumerate(nums):
            # Skip positive integers
            if a > 0:
                break

            # skip already processed element as it will create duplicate triplet
            if i > 0 and a == nums[i - 1]:
                continue

            l, r = i + 1, len(nums) - 1
            
            # at most O(n)
            while l < r:
                threeSum = a + nums[l] + nums[r]
                
                if threeSum > 0:
                    # decrease sum in sorted array
                    r -= 1
                elif threeSum < 0:
                    # increase sum in sorted array
                    l += 1
                else:
                    res.append([a, nums[l], nums[r]])
                    # already in sorted order
                    # j and k cannot be same elements hence forth
                    l += 1
                    r -= 1
                    # skip duplicates
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
                    while nums[r] == nums[r + 1] and l < r:
                        r -= 1
                        
        return res




