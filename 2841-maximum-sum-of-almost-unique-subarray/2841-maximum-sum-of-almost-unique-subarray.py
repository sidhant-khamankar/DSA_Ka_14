# did not get
# sliding window
# leetcode discuss solution
# On time 
# remove first element from window and add new element at last in window
# track unique and frequency using hash map
class Solution:
    def maxSum(self, nums: List[int], m: int, k: int) -> int:
        unique = 0
        ans = 0
        sum_of_window = 0
        number_count_map = defaultdict(int)
        l = 0
        r = 0 
        
        while r < len(nums):
            sum_of_window += nums[r]
            number_count_map[nums[r]] += 1
            if number_count_map[nums[r]] == 1:
                unique += 1;
            if r >= k:
                sum_of_window -= nums[l]
                number_count_map[nums[l]] -= 1
                if number_count_map[nums[l]] == 0:
                   unique -= 1
                l += 1
            
            if unique >= m:
                ans = max(ans, sum_of_window)
            r += 1
        
        return ans