class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        # O(n) time O(1) space
        nums = list(set(nums))
        if len(nums) == 0:
            return 0
        
        nums.sort()
        curr = 1
        maxi = 1
        for i in range(0, len(nums)-1):
            
            if i == len(nums)-2:
                if (nums[i+1]==nums[i]+1):
                    curr += 1
                maxi = max(curr, maxi) 
            elif nums[i+1] == nums[i] + 1:
                curr += 1
            else:
                maxi = max(curr, maxi)
                curr = 1
        
        return maxi
    
    # 0, 1, 1, 2
    # 2