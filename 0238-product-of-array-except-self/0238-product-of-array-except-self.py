class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Approach 1 - Multiply all elements and then traverse array and divide by element at that index. O(n) time O(1) space
        
        # Approach 2 Neetcode - Postfix Aand prefix array calculated and then multiplied
        # Can skip postfix and prefix array by putting prefix result in output array at one index greater than current index. 
        # O(n) time O(1) space
        
        res = [1] * len(nums)
        
        # prefix for 0th element
        prefix = 1
        
        # prefix result is stored at next adjacent position with reference to current position
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]
            
        # postfix for last element
        postfix = 1
        
        # multiply postfix and prefix starting from end
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= postfix
            postfix *= nums[i]
            
        return res
        
        
        
        
        
        
        
        
        