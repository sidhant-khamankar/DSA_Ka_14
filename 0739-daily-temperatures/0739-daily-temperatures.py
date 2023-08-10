# My solution O(n) time O(n) space like neetcode solution
class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ans = [None]*len(temperatures)
        stack = list()
        for index, temp in enumerate(temperatures):
            while len(stack) != 0 and temp > stack[-1][1]:
                ans[stack[-1][0]] = index - stack[-1][0]
                stack.pop()
            
            stack.append([index,temp])
        while len(stack) != 0:
            ans[stack[-1][0]] = 0
            stack.pop()
        
        return ans 

