class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = set()
        for idx, val in enumerate(nums):
            left = idx+1
            if left == len(nums):
                break
            right = len(nums)-1

            while left < right:
                target = nums[left] + nums[right] + val
                if target == 0:
                    ans.add((val, nums[left], nums[right]))
                    left += 1
                    right -= 1
                elif target > 0:
                    right -= 1
                else:
                    left += 1
        
        return list(ans)
                
                
