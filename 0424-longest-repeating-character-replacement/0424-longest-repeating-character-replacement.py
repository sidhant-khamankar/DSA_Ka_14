# did not get

# neetcode solution O(n*26) time O(26) space

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        
        l = 0
        maxf = 0
        res = 0
        for r in range(len(s)):
            count[s[r]] = 1 + count.get(s[r], 0)
            # maxf = max(maxf, count[s[r]])
            
            # total elements till r or current window length - max repeating set length till now <= k 
            # means we have valid window where we can do enough replacements to get answer
            # otherwise we have to shrink the window to make it valid
            # we do so by sliding the l right
            # if (r - l + 1) - maxf > k:
            #     count[s[l]] -= 1
            #     l += 1
            
            while (r-l+1) - max(count.values()) > k:
                count[s[l]] -= 1
                l += 1
            res = max(res, r-l+1)

        # return (r - l + 1)
        return res
