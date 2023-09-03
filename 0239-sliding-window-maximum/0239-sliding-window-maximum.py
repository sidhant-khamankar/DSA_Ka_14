import heapq
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # curr_window_set = set()
        max_heap = []
        ans = []
        l = 0 
        for r in range(len(nums)):
            # print(l,r, max_heap)
            if (r-l+1) > k:
                # print("-^-")
                max_in_curr_window, max_in_curr_window_index = heapq.heappop(max_heap)
                
                while max_in_curr_window_index < l:
                    max_in_curr_window, max_in_curr_window_index = heapq.heappop(max_heap)
                
                heapq.heappush(max_heap, (max_in_curr_window, max_in_curr_window_index))
                ans.append(-1 * max_in_curr_window)
                l += 1
                # curr_window_set.remove([l, nums[l]])
            
            # curr_window_set.add([l, nums[l]])
            heapq.heappush(max_heap, (-1*nums[r], r))
        
        max_in_curr_window, max_in_curr_window_index = heapq.heappop(max_heap)
                
        while max_in_curr_window_index < l:
            max_in_curr_window, max_in_curr_window_index = heapq.heappop(max_heap)
        ans.append(-1 * max_in_curr_window)
        return ans
            
                           
            
            
            
        
            
            
            