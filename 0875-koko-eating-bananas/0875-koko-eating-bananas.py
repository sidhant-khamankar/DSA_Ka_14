# My solution O(log(max(piles))*n) time O(1) space
# import math
# class Solution:
#     def minEatingSpeed(self, piles: List[int], actual_hrs: int) -> int:
#         # maximum k can be max(piles)
#         # minimum k can be 1
        
#         # find optimal minimum k
        
#         # binary search in this range to fix value of k
#         # sum of ceil of division of pile/k
#         # sum > h, then l = mid + 1
#         # sum <= h, store mid, h = mid - 1
        
        
#         l = 1
#         h = max(piles)
#         ans = None
        
#         while l<=h:
#             mid = l + (h-l)//2
            
#             division = [math.ceil(pile/mid) for pile in piles]
#             # print(l, h, mid)
#             # print(division)
#             hrs = sum(division)
#             # print(f"hrs: {hrs}, h: {h}")
#             if hrs > actual_hrs:
#                 l = mid + 1
                
#             else:
#                 h = mid - 1
#                 ans = mid
            
        
#         return ans


# neetcode solution like my solution
# O(log(max(piles))*n) time O(1) space
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        res = max(piles)

        while l <= r:
            k = (l + r) // 2

            totalTime = 0
            for p in piles:
                totalTime += math.ceil(p / k)
            if totalTime <= h:
                res = min(res, k)
                r = k - 1
            else:
                l = k + 1
        return res
