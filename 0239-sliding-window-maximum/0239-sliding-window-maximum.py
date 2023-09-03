# Neetcode solution
# O(n) time O(n) space
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        output = []
        q = collections.deque()  # indexes
        l = r = 0
        # O(n) O(n)
        while r < len(nums):
            # pop values from end which are smaller than current value in deque
            while q and nums[q[-1]] < nums[r]:
                q.pop()
                
            # add current value to deque
            q.append(r)

            # if window is out of bounds
            # remove left val from window
            if l > q[0]:
                q.popleft()
            
            # skip untill end of first window is reached
            if (r + 1) >= k:
                output.append(nums[q[0]])
                l += 1
            r += 1

        return output


# My solution Max heap
# High time complexity
# On^2 time On/k space
# import heapq
# class Solution:
#     def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
#         # curr_window_set = set()
#         max_heap = []
#         ans = []
#         l = 0 
#         for r in range(len(nums)):
#             # print(l,r, max_heap)
#             if (r-l+1) > k:
#                 # print("-^-")
#                 max_in_curr_window, max_in_curr_window_index = heapq.heappop(max_heap)
                
#                 while max_in_curr_window_index < l:
#                     max_in_curr_window, max_in_curr_window_index = heapq.heappop(max_heap)
                
#                 heapq.heappush(max_heap, (max_in_curr_window, max_in_curr_window_index))
#                 ans.append(-1 * max_in_curr_window)
#                 l += 1
#                 # curr_window_set.remove([l, nums[l]])
            
#             # curr_window_set.add([l, nums[l]])
#             heapq.heappush(max_heap, (-1*nums[r], r))
        
#         max_in_curr_window, max_in_curr_window_index = heapq.heappop(max_heap)
                
#         while max_in_curr_window_index < l:
#             max_in_curr_window, max_in_curr_window_index = heapq.heappop(max_heap)
#         ans.append(-1 * max_in_curr_window)
#         return ans
            
                           
            
            
            
        
            
            
            