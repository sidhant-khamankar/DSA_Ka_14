# Neetcode solution, Leetcode solution
# How does this approach work?

# Initially we consider the area constituting the exterior most lines. 
# Now, to maximize the area, we need to consider the area
# between the lines of larger lengths. If we try to move the pointer
# at the longer line inwards, we won't gain any increase in area,
# since it is limited by the shorter line. But moving the shorter
# line's pointer could turn out to be beneficial, as per the same
# argument, despite the reduction in the width. This is done since a
# relatively longer line obtained by moving the shorter line's pointer
# might overcome the reduction in area caused by the width reduction.

class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        res = 0
        h = max(height)
        
        # O(n) time O(1) space
        while l < r:
            res = max(res, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            elif height[r] <= height[l]:
                r -= 1
            
        return res
