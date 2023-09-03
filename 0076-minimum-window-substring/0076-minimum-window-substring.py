# Did not get
# Neetcode Solution, Leetcode solution similar
# O(s+t) time O(s+t) space
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        # t is empty string
        if t == "":
            return ""
        
        # t and s dictionary
        countT, window = {}, {}
        
        # t dictionary with frequency count of characters
        for c in t:
            countT[c] = 1 + countT.get(c, 0)

        have, need = 0, len(countT)
        
        # result position, result length
        res, resLen = [-1, -1], float("infinity")
        
        # start position
        l = 0
        
        # traverse s string
        for r in range(len(s)):
            c = s[r]
            # update frequency of current character in window dictionary
            window[c] = 1 + window.get(c, 0)
            
            # check if c is present in t's dictionary and if its occurrence is equal in both dictionaries
            if c in countT and window[c] == countT[c]:
                have += 1
            
            # all characters of t are present in current s substring
            while have == need:
                # update our result
                if (r - l + 1) < resLen:
                    res = [l, r]
                    resLen = r - l + 1
                # pop from the left of our window
                window[s[l]] -= 1
                
                # check if leftmost character is present in t's dictionary and if its occurrence is less in s's dictionary
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                
                # popped from left
                l += 1
        l, r = res
        return s[l : r + 1] if resLen != float("infinity") else ""
