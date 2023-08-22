# My solution On^2 time On space
from collections import defaultdict
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        if len(s) == 0:
            return 0
        
        if len(s) == 1:
            return 1
        
        
        start = 0
        end = 0
        
        dic = defaultdict(int)

        max_length = 1
        
        while end < len(s):
            
            dic[s[end]] += 1
            
            # print(s[start], s[end])
            # print(dic)
            while dic[s[end]] == 2:
                dic[s[start]] -= 1
                start += 1
                
            max_length = max(max_length, end - start + 1)

            # print(start, end, max_length)
            end += 1
        
        return max_length
            
            
            