# Striver Solution
'''
* Internal inbuilt next_permutation function
* Bruteforce On!*n time On space: Generate all possible permutations and find next, if it is last then answer is first permutation
* Optimal On time O1 space

# Leetcode solution
First, we observe that for any given sequence that is in descending order, no next larger permutation is possible.
We need to find the first pair of two successive numbers a[i] and a[i−1], from the right, which satisfy a[i]>a[i−1]. Now, no rearrangements to the right of a[i−1] can create a larger permutation since that subarray consists of numbers in descending order.
Thus, we need to rearrange the numbers to the right of a[i−1] including itself.

Now, what kind of rearrangement will produce the next larger number? We want to create the permutation just larger than the current one. Therefore, we need to replace the number a[i−1] with the number which is just larger than itself among the numbers lying to its right section, say a[j].

# ref image in leetcode solution

We swap the numbers a[i−1] and a[j]. We now have the correct number at index i−1. But still the current permutation isn't the permutation that we are looking for. We need the smallest permutation that can be formed by using the numbers only to the right of a[i−1]. Therefore, we need to place those numbers in ascending order to get their smallest permutation.

But, recall that while scanning the numbers from the right, we simply kept decrementing the index until we found the pair a[i] and a[i−1] where, a[i]>a[i−1]. Thus, all numbers to the right of a[i−1] were already sorted in descending order.
Furthermore, swapping a[i−1] and a[j] didn't change that order.
Therefore, we simply need to reverse the numbers following a[i−1] to get the next smallest lexicographic permutation.

The following animation will make things clearer:

# ref animation in leetcode solution
'''

class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0 and nums[i + 1] <= nums[i]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            self.swap(nums, i, j)
        self.reverse(nums, i + 1)

    def reverse(self, nums, start):
        i, j = start, len(nums) - 1
        while i < j:
            self.swap(nums, i, j)
            i += 1
            j -= 1

    def swap(self, nums, i, j):
        temp = nums[i]
        nums[i] = nums[j]
        nums[j] = temp

# Did not get