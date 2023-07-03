class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq = dict()
        for c in s:
            if c in freq.keys():
                freq[c]+=1
            else:
                freq[c] = 1;
            
        for c in t:
            if c in freq.keys():
                freq[c]-=1
            else:
                return False
            
        for v in freq.values():
            if v != 0:
                return False;
            
        return True;