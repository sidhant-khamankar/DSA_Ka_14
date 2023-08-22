# My solution On^2 time On space
# from collections import defaultdict
# class Solution:
#     def lengthOfLongestSubstring(self, s: str) -> int:
        
#         if len(s) == 0:
#             return 0
        
#         if len(s) == 1:
#             return 1
        
        
#         start = 0
#         end = 0
        
#         dic = defaultdict(int)

#         max_length = 1
        
#         while end < len(s):
            
#             dic[s[end]] += 1
            
#             # print(s[start], s[end])
#             # print(dic)
#             while dic[s[end]] == 2:
#                 dic[s[start]] -= 1
#                 start += 1
                
#             max_length = max(max_length, end - start + 1)

#             # print(start, end, max_length)
#             end += 1
        
#         return max_length
    
# neetcode solution like my solution
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charSet = set()
        l = 0
        res = 0

        for r in range(len(s)):
            while s[r] in charSet:
                charSet.remove(s[l])
                l += 1
            charSet.add(s[r])
            res = max(res, r - l + 1)
        return res

# // Striver solution 
# Optimal On (average case O1 unordered map but On in worst case) time On space:
# ```
# Map to store indexes of duplicates
# move r, check map and if not found then put element,index in map and update length
# else if it already exists, move l to map[element]+1, then update index of element and move r, l moved so other duplicates indexes are left behind
# ```
# ```
#         
#         // On (average case O1 unordered map but On in worst case) time On space
#         vector<int> mpp(256, -1);
#         // or map character, int

#         int left = 0, right = 0;
#         int n = s.size();
#         int len = 0;
#         while (right < n)
#         {
#             if (mpp[s[right]] != -1)
#                 left = max(mpp[s[right]] + 1, left);
#             mpp[s[right]] = right;

#             len = max(len, right - left + 1);
#             right++;
#         }
#         return len;
            
            
            