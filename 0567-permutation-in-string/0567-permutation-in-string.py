# did not get
# neetcode solution
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        # all 26 alphabets counts in both string
        s1Count, s2Count = [0] * 26, [0] * 26
        for i in range(len(s1)):
            s1Count[ord(s1[i]) - ord("a")] += 1
            s2Count[ord(s2[i]) - ord("a")] += 1
        
        # initials number of matches in both count arrays
        matches = 0
        for i in range(26):
            matches += 1 if s1Count[i] == s2Count[i] else 0

        # slide window
        # O(n)
        # index of first character in string 2 window
        l = 0
        for r in range(len(s1), len(s2)):
            # both count arrays matches exactly
            if matches == 26:
                return True
            
            # remove first character in string 2 window and append next character
            
            # remove first character
            index = ord(s2[r]) - ord("a")
            # increment in string 2's count array
            s2Count[index] += 1
            
            # update matches
            if s1Count[index] == s2Count[index]:
                matches += 1
            # if it was matching earlier but not it isn't
            elif s1Count[index] + 1 == s2Count[index]:
                matches -= 1
            
            # append next character
            index = ord(s2[l]) - ord("a")
            s2Count[index] -= 1
            
            # update matches
            if s1Count[index] == s2Count[index]:
                matches += 1
            # if it was matching earlier but not it isn't
            elif s1Count[index] - 1 == s2Count[index]:
                matches -= 1
            l += 1
        return matches == 26
