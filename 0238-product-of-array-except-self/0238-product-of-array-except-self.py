class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Approach 1 - Multiply all elements and then traverse array and divide by element at that index. O(n) time O(1) space
        
        # Approach 2 Neetcode - Postfix Aand prefix array calculated and then multiplied
        # Can skip postfix and prefix array by putting prefix result in output array at one index greater than current index
        
        res = [1] * len(nums)
        
        prefix = 1
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]
        postfix = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]
            
        return res
        
        
        
        
        
        
        
        
        