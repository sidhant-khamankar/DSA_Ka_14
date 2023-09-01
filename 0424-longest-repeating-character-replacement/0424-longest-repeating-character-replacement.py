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



# class Solution:
#     def characterReplacement(self, s: str, k: int) -> int:
#         # think about skipping of resetting current repeat count and moving forward
        
#         # org_k = k
#         # max_repeating_len = 0
        
#         # recur(count, k, index, curr_char)

        
#         # if k = 0 or index >= len(s)
#             # return count 
            
        
        
#         # count = 0
#         # curr_char = ''
#         # traverse string s with character c
        
#             # if curr_char = ""
#                 # count ++
#                 # curr_char = c
#             # else if c == curr_char
#                 # count++
#             # else
#                 # if k > 0
#                     # max_repeating_len = max(max_repeating_len, recur(count+1, k - 1, index+1))
#                 # curr_char = c
#                 # max_repeating_len = max(max_repeating_len, recur(1, org_k, index + 1))
                
        
#         org_k = k
#         max_repeating_len = 0
        
#         # print("k, index, curr_char, count")
#         def recur(count, k, index, curr_char):
#             nonlocal max_repeating_len
#             # print(k, index, curr_char, count)

#             for i in range(index, len(s)):
#                 if s[i] == curr_char:
#                     count += 1
#                     max_repeating_len = max(max_repeating_len, count)
#                 else:
#                     if k>0:
#                         recur(count + 1, k-1, index + 1, curr_char)
#                     recur(1, org_k, index + 1, s[i])
        
        
#         recur(1, org_k, 1, s[0])
#         return max_repeating_len 
                
        