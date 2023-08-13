class Solution:
    # @param height, a list of integer
    # @return an integer
    # techdose solution 
    # On time On space
    # for element i get the index of element whose next/previous element has height less than ith element's height
    # (left - right) * current_height is area using height of ith index element
    def largestRectangleArea(self, heights):
        n = len(heights);
        # left containes leftmost index from i where height is less than height[i]
        # similarly right
        left, right = n*[1], n*[1]

        mystack = list()
        for i, curr_height in enumerate(heights): 
        #Fill left
            if len(mystack) == 0:
                left[i] = 0
                mystack.append(i)
                
            else:
                while len(mystack) != 0 and heights[mystack[-1]] >= curr_height:
                    mystack.pop()
                left[i] =  0 if len(mystack) == 0 else mystack[-1] + 1
                mystack.append(i)
            
        
        mystack = []

        for i in range(n-1,-1,-1):
        # Fill right
            if len(mystack) == 0:
            
                right[i] = n - 1
                mystack.append(i)
            
            else:
            
                while len(mystack) != 0 and heights[mystack[-1]] >= heights[i]:
                    mystack.pop()
                right[i] = n - 1 if len(mystack) == 0 else mystack[-1] - 1
                mystack.append(i)
            
        
        mx_area = 0 # Stores max_area
        for i in range(n):
            mx_area = max(mx_area, heights[i] * (right[i] - left[i] + 1))
        return mx_area
  
# neetcode solution
# On time On space
# different approach to store and update starting of rectangle 
# class Solution:
#     def largestRectangleArea(self, heights: List[int]) -> int:
#         maxArea = 0
#         stack = []  # pair: (index, height)

#         for i, h in enumerate(heights):
#             start = i
#             while stack and stack[-1][1] > h:
#                 index, height = stack.pop()
#                 maxArea = max(maxArea, height * (i - index))
#                 start = index
#             stack.append((start, h))

#         for i, h in stack:
#             maxArea = max(maxArea, h * (len(heights) - i))
#         return maxArea



# TLE My solution
# class Solution:
#     def largestRectangleArea(self, heights: List[int]) -> int:
#         # for each current height
#             # get leftmost index where height is greater than or equal to current height
#             # get rightmost index where height is greater than or equal to current height
#             # replace max with maximum of max and curr height * leftmost index - rightmost index + 1
            
#         maxi = 0
#         for index, height in enumerate(heights):
#             l = index
#             r = index
#             while l>=0 and heights[l] >= height:
#                 l-=1
#             l += 1
#             while r < len(heights) and heights[r] >= height:
#                 r+=1
#             r -= 1
            
#             maxi = max(maxi, height * (r-l + 1))
#             # print(f"maxi = {maxi} => {height} * ({r} - {l} + 1)")
            
            
#         return maxi
            